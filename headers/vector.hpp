#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "enable_if.hpp"
#include "is_integral.hpp"
#include "iterator_traits.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"

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

		private :

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
				if (n > this->max_size())
					throw std::length_error("vector::not enough capacity");
				if (n > 0)
				{
					this->_array = this->_allocator.allocate(n);
					for (size_t i = 0; i < n; i++)
						this->_allocator.construct(this->_array + i, val);
				}
			}

			template< class InputIterator >
			vector( InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, void **>::type = 0 ) : _allocator(alloc), _size(0), _capacity(0), _array(0) {

				if (first != last)
					this->reserve(1);
				size_type i = 0;
				for (; first != last; first++)
				{
					if (i == this->_capacity)
						this->reserve(this->_capacity * 2);
					this->_allocator.construct(this->_array + i++, *first);
					this->_size++;
				}
				this->shrink_to_fit();
			}

			vector( const vector & x ) : _size(0), _capacity(0), _array(NULL) {
				if (this->_capacity)
				{
					for (size_type i = 0; i < this->_size; i++)
						this->_allocator.destroy(this->_array + i);
					this->_allocator.deallocate(this->_array, this->_capacity);
				}
				this->_allocator = x.get_allocator();
				this->_size = x.size();
				this->_capacity = x.size();
				if (x.size() > 0)
				{
					this->_array = this->_allocator.allocate(this->_capacity);
					for (size_type i = 0; i < x.size(); i++)
						this->_allocator.construct(this->_array + i, x.at(i));
				}
			}

			vector & operator=( const vector & x ) {
				if (this != &x)
				{
					this->clear();
					this->assign(x.begin(), x.end());
				}
				return *this;
			}

			~vector( void ) {
				for (size_type i = 0; i < this->_size; i++)
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
				if (n > this->max_size())
					throw std::length_error("vector::resize");
				if (n == this->_size)
					return ;
				else if (n < this->_size) {
					for (size_type i = n; i < this->_size; i++)
						this->_allocator.destroy(this->_array + i);
					this->_size = n;
				}
				else if (n > this->_size) {
					if (n > this->_capacity)
					{
						size_type tmp_capacity;
						if (n > this->_size * 2)
							tmp_capacity = n;
						else
							tmp_capacity = this->_size * 2;
						pointer tmp = this->_allocator.allocate(tmp_capacity);
						int i = 0;
						for (iterator it = this->begin(); it != this->end(); it++)
							this->_allocator.construct(tmp + i++, *it);
						if (this->_capacity)
						{
							for (size_type i = 0; i < this->_size; i++)
								this->_allocator.destroy(this->_array + i);
							this->_allocator.deallocate(this->_array, this->_capacity);
						}
						this->_array = tmp;
						this->_capacity = tmp_capacity;
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

				if (n > this->max_size())
					throw std::length_error("vector::reserve");
				if (n > this->_capacity) {
					pointer tmp = this->_allocator.allocate(n);
					int i = 0;
					for (iterator it = this->begin(); it != this->end(); it++)
						this->_allocator.construct(tmp + i++, *it);
					if (this->_capacity)
					{
						for (size_type i = 0; i < this->_size; i++)
							this->_allocator.destroy(this->_array + i);
						this->_allocator.deallocate(this->_array, this->_capacity);
					}
					this->_array = tmp;
					this->_capacity = n;
				}
			}

			void shrink_to_fit( void ) {
				if (this->_capacity != this->_size)
				{
					pointer tmp = this->_allocator.allocate(this->_size);
					iterator it = this->begin();
					for (size_type i = 0; i < this->_size; i++)
					{
						this->_allocator.construct(tmp + i, *it);
						it++;
					}
					size_type size = this->_size;
					this->clear();
					this->_allocator.deallocate(this->_array, this->_capacity);
					this->_array = tmp;
					this->_size = size;
					this->_capacity = size;
				}
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

			value_type * data( void ) const {
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

				if (this->_capacity == 0)
					this->reserve(1);
				size_type i = 0;
				for (; first != last; first++)
				{
					if (i == this->_capacity)
						this->reserve(this->_capacity * 2);
					this->_allocator.construct(this->_array + i++, *first);
					this->_size++;
				}
			}

			void assign( size_type n, const value_type & val ) {
				if (n > this->max_size())
					throw std::length_error("vector::assign");
				this->clear();
				if (this->_capacity < n) {
					if (this->_capacity)
					{
						for (size_type i = 0; i < this->_size; i++)
							this->_allocator.destroy(this->_array + i);
						this->_allocator.deallocate(this->_array, this->_capacity);
					}
					this->_array = this->_allocator.allocate(n);
					this->_capacity = n;
				}
				for (size_type i = 0; i < n; i++)
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
					this->_allocator.destroy(this->_array + this->_size - 1);
					this->_size--;
				}
			}

			iterator insert( iterator position, const value_type & val ) {

				difference_type diff = position - this->begin();

				if (this->_capacity == 0)
					this->reserve(1);
				if (this->_capacity == this->_size)
					this->reserve(this->_size * 2);

				pointer index = this->_array + this->_size;
				pointer end = this->_array + diff;

				for (; index != end; index--)
				{
					this->_allocator.construct(index, *(index - 1));
					this->_allocator.destroy(index - 1);
				}
				this->_allocator.construct(index, val);
				this->_size++;
				return iterator(index);
			}

			void insert( iterator position, size_type n, const value_type & val ) {
				if (n > this->max_size())
					throw std::length_error("vector::insert");
				if (!n)
					return;

				iterator it = this->begin();
				while (it != this->end() && it != position) {it++;}
				if (it == this->end() && it != position)
					return ;

				difference_type diff = position - this->begin();

				if (this->_capacity < this->_size + n)
				{
					if (this->_size + n <= this->_size * 2)
						this->reserve(this->_size * 2);
					else
						this->reserve(this->_size + n);
				}
				
				pointer index = this->_array + this->_size + n - 1;
				pointer end = this->_array + diff + n - 1;

				for (; index != end; index--)
				{
					this->_allocator.construct(index, *(index - n));
					this->_allocator.destroy(index - n);
				}
				for (size_type i = 0; i < n; i++)
					this->_allocator.construct(index - i, val);
				this->_size += n;
			}

			template< class InputIterator >
			void insert( iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, void **>::type = 0 ) {
				for (; first != last; first++)
					position = this->insert(position, *first) + 1;
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

				allocator_type tmp_allocator = x.get_allocator();
				x._allocator = this->_allocator;
				this->_allocator = tmp_allocator;

				pointer tmp_array = x._array;
				x._array = this->_array;
				this->_array = tmp_array;

				size_type tmp_capacity = x.capacity();
				x._capacity = this->_capacity;
				this->_capacity = tmp_capacity;

			}

			void clear( void ) {
				if (this->_size) {
					for (size_type i = 0; i < this->_size; i++)
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
