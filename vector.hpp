#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iterator>
#include <iostream>
#include <memory>
#include <stdexcept>

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector {
	
		public :

			typedef T							value_type;
			typedef Alloc							allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename ft::random_access_iterator<value_type>		iterator;
			typedef typename ft::random_access_iterator<const value_type>	const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t							size_type;

		protected :

			allocator_type	_allocator;
			size_type	_size;
			size_type	_capacity;
			pointer		_array;

		public :

	/*-----------------------------------------------------------------------------------------*/
	/*                                                                                         */
	/*                                                                                         */
	/*                                CONSTRUCTOR / DESTRUCTOR                                 */
	/*                                                                                         */
	/*                                                                                         */
	/*-----------------------------------------------------------------------------------------*/

			explicit vector( const allocator_type & alloc = allocator_type() ) : _allocator(alloc), _size(0), _capacity(0), _array(0) {}

			explicit vector( size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type() ) : _allocator(alloc), _size(n), _capacity(n), _array(0) {
				if (n > 0)
				{
					this->_array = this->_allocator.allocate(n);
					for (size_t i = 0; i < n; i++)
						this->_allocator.construct(this->_array + i, val);
				}
			}

			template< class InputIterator >
			vector( InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type() ) : _allocator(alloc), _size(static_cast<size_type>(std::distance(first, last))), _capacity(static_cast<size_type>(std::distance(first, last))), _array(0) {
				this->_array = this->_allocator.allocate(this->_size);
				InputIterator tmp = first;
				for (size_t i = 0; i < this->_size; i++)
					this->_allocator.construct(this->_array + i, *tmp++);
			}

			vector( const vector & x ) {
				*this = x;
			}

			vector & operator=( const vector & x ) {
				this->_allocator = x.get_allocator();
				this->_size = x.size();
				this->_capacity = x.capacity();
				if (x.size() > 0)
				{
					this->_array = this->_allocator.allocate(this->_capacity);
					for (size_t i = 0; i < x.size(); i++)
						this->_allocator.construct(this->_array + i, x[i]);
				}
				return *this;
			}

			~vector( void ) {
				for (size_t i = 0; i < this->_size; i++)
					this->_allocator.destroy(this->_array + i);
				if (this->_capacity > 0)
					this->_allocator.deallocate(this->_array, this->_capacity);
			}

	/*-----------------------------------------------------------------------------------------*/
	/*                                                                                         */
	/*                                                                                         */
	/*                                        ITERATOR                                         */
	/*                                                                                         */
	/*                                                                                         */
	/*-----------------------------------------------------------------------------------------*/

			iterator begin( void ) {
				return iterator(this->_array);
			}

			const_iterator begin( void ) const {
				return const_iterator(this->_array);
			}

			iterator end( void ) {
				return iterator(this->_array + this->_size);
			}

			const_iterator end( void ) const {
				return const_iterator(this->_array + this->_size);
			}

			reverse_iterator rbegin( void ) {
				return reverse_iterator(this->end());
			}

			const_reverse_iterator rbegin( void ) const {
				return const_reverse_iterator(this->end());
			}

			reverse_iterator rend( void ) {
				return reverse_iterator(this->begin());
			}

			const_reverse_iterator rend( void ) const {
				return const_reverse_iterator(this->begin());
			}

	/*-----------------------------------------------------------------------------------------*/
	/*                                                                                         */
	/*                                                                                         */
	/*                                        CAPACITY                                         */
	/*                                                                                         */
	/*                                                                                         */
	/*-----------------------------------------------------------------------------------------*/

			size_type size( void ) const {
				return this->_size;
			}

			size_type max_size( void ) const {
				return this->_allocator.max_size();
			}

			void resize( size_type n, value_type val = value_type() ) {
				if (n == this->_size)
					return ;
				else if (n < this->_size) {
					for (size_t i = n; i < this->_size; i++)
						this->_allocator.destroy(this->_array + i);
					this->_size = n;
				}
				else if (n > this->_size) {
					if (n > this->_capacity)
					{
						pointer tmp = this->_allocator.allocate(n);
						int i = 0;
						for (iterator it = this->begin(); it != this->end(); it++)
							this->_allocator.construct(tmp + i++, *it);
						this->_allocator.deallocate(this->_array, this->_capacity);
						this->_array = tmp;
						this->_capacity = n;
					}
					for (size_t i = this->_size; i < n; i++)
						this->_allocator.construct(this->_array + i, val);
					this->_size = n;
				}
			}

			size_type capacity( void ) const {
				return this->_capacity;
			}

			bool empty( void ) const {
				return (!(this->_size));
			}

			void reserve( size_type n ) {

				if (n > this->_capacity) {
					pointer tmp = this->_allocator.allocate(n);
					int i = 0;
					for (iterator it = this->begin(); it != this->end(); it++)
						this->_allocator.construct(tmp + i++, *it);
					this->_allocator.deallocate(this->_array, this->_capacity);
					this->_array = tmp;
					this->_capacity = n;
				}
			}

			void shrink_to_fit( void ) {
				if (this->_size != this->_capacity)
					this->_allocator.deallocate(this->_array + this->_size, this->_capacity - this->_size);
				this->_capacity = this->_size;
			}

	/*-----------------------------------------------------------------------------------------*/
	/*                                                                                         */
	/*                                                                                         */
	/*                                     ELEMENT ACCESS                                      */
	/*                                                                                         */
	/*                                                                                         */
	/*-----------------------------------------------------------------------------------------*/

			reference operator[]( size_type n ) {
				return (this->_array[n]);
			}

			const_reference operator[]( size_type n ) const {
				return (this->_array[n]);
			}

			reference at( size_type n ) {
				if (n >= this->_size)
					throw std::out_of_range("vector::[] -> index out of range !");
				return (this->_array[n]);
			}

			const_reference at( size_type n ) const {
				if (n >= this->_size)
					throw std::out_of_range("vector::[] -> index out of range !");
				return (this->_array[n]);
			}

			reference front( void ) {
				return this->_array[0];
			}

			const_reference front( void ) const {
				return this->_array[0];
			}

			reference back( void ) {
				if (this->_size > 0)
					return this->_array[this->_size - 1];
				else
					return this->_array[0];
			}

			const_reference back( void ) const {
				if (this->_size > 0)
					return this->_array[this->_size - 1];
				else
					return this->_array[0];
			}

			value_type * data( void ) {
				return this->_array;
			}

	/*-----------------------------------------------------------------------------------------*/
	/*                                                                                         */
	/*                                                                                         */
	/*                                       MODIFIERS                                         */
	/*                                                                                         */
	/*                                                                                         */
	/*-----------------------------------------------------------------------------------------*/

			template< class InputIterator >
			void assign( InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, void **>::type = 0 ) {
				this->clear();
				this->insert(this->begin(), first, last);
			}

			void assign( size_type n, const value_type & val ) {
				this->clear();
				if (this->_capacity < n) {
					this->_allocator.deallocate(this->_array, this->_capacity);
					this->_array = this->_allocator.allocate(n);
					this->_capacity = n;
				}
				for (size_t i = 0; i < n; i++)
					this->_allocator.construct(this->_array + i, val);
				this->_size = n;
			}

			void push_back( const value_type & val ) {
				if (this->_capacity == 0)
					this->reserve(1);
				else if (this->_capacity == this->_size)
					this->reserve(this->_size * 2);
				this->_allocator.construct(this->_array + this->_size, val);
				this->_size++;
			}

			void pop_back( void ) {
				if (this->_size > 0) {
					this->_allocator.destroy(this->_array + this->_size);
					this->_size--;
				}
			}

			iterator insert( iterator position, const value_type & val ) {
				if (this->_capacity == this->_size)
					this->reserve(this->_size * 2);

				difference_type diff = position - this->begin();
				pointer index = this->_array + this->_size;
				pointer end = this->_array + diff;

				for (; index != end; index--)
				{
					this->_allocator.construct(index, *(index - 1));
					this->_allocator.destroy(index - 1);
				}
				this->_allocator.construct(index, val);
				this->_size++;
				return position;
			}

			void insert( iterator position, size_type n, const value_type & val ) {
				if (!n)
					return;

				if (this->_capacity < this->_size + n)
					this->reserve(this->_size + n);
				
				difference_type diff = position - this->begin();
				pointer index = this->_array + this->_size + n - 1;
				pointer end = this->_array + diff + n - 1;

				for (; index != end; index--)
				{
					this->_allocator.construct(index, *(index - n));
					this->_allocator.destroy(index - n);
				}
				for (size_t i = 0; i < n; i++)
					this->_allocator.construct(index - i, val);
				this->_size += n;
			}

			template< class InputIterator >
			void insert( iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, void **>::type = 0 ) {
				difference_type n = last - first;

				if (this->_capacity < this->_size + n)
					this->reserve(this->_size + n);

				difference_type diff = position - this->begin();
				pointer index = this->_array + this->_size + n - 1;
				pointer end = this->_array + diff + n - 1;

				for (; index != end; index--)
				{
					this->_allocator.construct(index, *(index - n));
					this->_allocator.destroy(index - n);
				}
				for (size_t i = 0; i < n; i++)
					this->_allocator.construct(index - i, *(--last));
				this->_size += n;
			}

			iterator erase( iterator position ) {
				pointer tmp = this->_array;
				iterator it = this->begin();
				while (it != position) {
					it++;
					tmp++;
				}
				while (++it != this->end()) {
					*tmp = *(tmp + 1);
					tmp++;
				}
				this->_allocator.destroy(tmp);
				this->_size--;
				return position;
			}

			iterator erase( iterator first, iterator last ) {
				iterator tmp = first;
				while (first != last) {
					this->erase(first);
					last--;
				}
				return tmp;
			}

			void swap( vector & x ) {
				size_type tmp_size = x.size();
				x._size = this->_size;
				this->_size = tmp_size;

				size_type tmp_capacity = x.capacity();
				x._capacity = this->_capacity;
				this->_capacity = tmp_capacity;

				pointer tmp_array = x._array;
				x._array = this->_array;
				this->_array = tmp_array;
			}

			void clear( void ) {
				if (this->_size) {
					for (size_t i = 0; i < this->_size; i++)
						this->_allocator.destroy(this->_array + i);
				}
				this->_size = 0;
			}

	/*-----------------------------------------------------------------------------------------*/
	/*                                                                                         */
	/*                                                                                         */
	/*                                       ALLOCATOR                                         */
	/*                                                                                         */
	/*                                                                                         */
	/*-----------------------------------------------------------------------------------------*/

			allocator_type get_allocator( void ) const {
				return this->_allocator;
			}

	};

	/*-----------------------------------------------------------------------------------------*/
	/*                                                                                         */
	/*                                                                                         */
	/*                                NON MEMBER FUNCTIONS                                     */
	/*                                                                                         */
	/*                                                                                         */
	/*-----------------------------------------------------------------------------------------*/

	template< class T, class Alloc >
	bool operator==( const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs ) {
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template< class T, class Alloc >
	bool operator!=( const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs ) {
		return !(lhs == rhs);
	}

	template< class T, class Alloc >
	bool operator<( const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs ) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template< class T, class Alloc >
	bool operator<=( const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs ) {
		return !(rhs < lhs);
	}

	template< class T, class Alloc >
	bool operator>( const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs ) {
		return (rhs < lhs);
	}

	template< class T, class Alloc >
	bool operator>=( const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs ) {
		return !(lhs < rhs);
	}

	template< class T, class Alloc >
	void swap( vector<T, Alloc> & x, vector<T, Alloc> & y ) {
		x.swap(y);
	}

}

#endif
