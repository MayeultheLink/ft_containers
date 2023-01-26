#ifndef MAP_HPP
#define MAP_HPP

#include <cstddef>
#include <functional>

#include "bst_iterator.hpp"
#include "binary_search_tree.hpp"

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class map {
		
		public :

			typedef Key							key_type;
			typedef T							mapped_type;
			typedef typename ft::pair<const key_type, mapped_type>		value_type;
			typedef Compare							key_compare;
			typedef Alloc							allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename ft::bst_iterator<value_type>			iterator;
			typedef typename ft::bst_iterator<const value_type>		const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t							size_type;
			
			class value_compare {
				private :
					Compare v_comp;
				public :
					value_compare(Compare c) : v_comp(c) {}
					bool operator()(const value_type & x, const value_type & y ) const {
						return (v_comp(x.first, y.first));
					}
			};

		private :

			binary_search_tree<value_type>	_tree;
			size_type			_size;
			allocator_type			_alloc;
			key_compare			_key_comp;
			value_compare			_value_comp;

		public :

	/*-----------------------------------------------------------------------------------------*/
	/*                                                                                         */
	/*                                                                                         */
	/*                                    CONSTRUCTORS                                         */
	/*                                                                                         */
	/*                                                                                         */
	/*-----------------------------------------------------------------------------------------*/

			explicit map ( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0), _alloc(alloc), _key_comp(comp), _value_comp(value_compare(comp)) {}

			template <class InputIterator>
			map ( InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0), _alloc(alloc), _key_comp(comp), _value_comp(value_compare(comp)) {
				while (first != last)
					this->insert(*first++);
			}

			map ( const map & x ) : _alloc(x.get_allocator()), _key_comp(x.key_comp()), _value_comp(x.value_comp()) {
				this = x;
			}

			map & operator=( const map & rhs ) {
				this->_size = rhs.size();
				this->_tree = rhs->_tree;
			}

			~map( void ) {}

	/*-----------------------------------------------------------------------------------------*/
	/*                                                                                         */
	/*                                                                                         */
	/*                                        ITERATOR                                         */
	/*                                                                                         */
	/*                                                                                         */
	/*-----------------------------------------------------------------------------------------*/

			iterator begin( void ) {
				return iterator(this->_tree.first_element());
			}

			const_iterator begin( void ) const {
				return const_iterator(this->_tree.first_element());
			}

			iterator end( void ) {
				return iterator(this->_tree.last_element());
			}

			const_iterator end( void ) const {
				return const_iterator(this->_tree.last_element());
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
	/*                                     CAPACITY                                            */
	/*                                                                                         */
	/*                                                                                         */
	/*-----------------------------------------------------------------------------------------*/

			bool empty( void ) const {
				if (!this->size())
					return true;
				return false;
			}

			size_type size( void ) const {
				return this->_size;
			}

			size_type max_size( void ) const {
				return this->_alloc.max_size();
			}

	/*-----------------------------------------------------------------------------------------*/
	/*                                                                                         */
	/*                                                                                         */
	/*                                    MODIFIERS                                            */
	/*                                                                                         */
	/*                                                                                         */
	/*-----------------------------------------------------------------------------------------*/

			ft::pair<iterator, bool> insert( const value_type & val ) {

				iterator i = this->begin();
				while (i != this->end() && i->first != val.first)
					i++;

				if (i != this->end() && !key_compare()(val.first, i->first) && !key_compare()(i->first, val.first))
					return (ft::pair<iterator, bool>(i, false));
				else
					return (this->_size++, ft::pair<iterator, bool>(iterator(this->_tree.insert(val)), true));
			}

	/*-----------------------------------------------------------------------------------------*/
	/*                                                                                         */
	/*                                                                                         */
	/*                                    OBSERVERS                                            */
	/*                                                                                         */
	/*                                                                                         */
	/*-----------------------------------------------------------------------------------------*/

			key_compare key_comp( void ) const {
				return (this->_key_comp);
			}

			value_compare value_comp( void ) const {
				return this->_value_comp;
			}

	/*-----------------------------------------------------------------------------------------*/
	/*                                                                                         */
	/*                                                                                         */
	/*                                    ALLOCATOR                                            */
	/*                                                                                         */
	/*                                                                                         */
	/*-----------------------------------------------------------------------------------------*/

			allocator_type get_allocator( void ) const {
				return this->_alloc;
			}
	};

}

#endif
