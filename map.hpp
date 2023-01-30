#ifndef MAP_HPP
#define MAP_HPP

#include <cstddef>
#include <functional>

#include "node.hpp"
#include "bst_iterator.hpp"

/*template< class T >
struct s_node {

	typedef T	value_type;

	s_node*		parent;
	s_node*		left;
	s_node*		right;
	value_type	root;

	s_node( const value_type & val ) : root(val), parent(NULL), left(NULL), right(NULL) {}

};*/

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class map {
		
		public :

			typedef Key							key_type;
			typedef T							mapped_type;
			typedef typename ft::pair<const key_type, mapped_type>		value_type;
			typedef Compare							key_compare;
			typedef s_node<value_type>					node;
			typedef std::allocator<node>					allocator_type;
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

			node*		_tree;
			node*		_end;
			size_type	_size;
			allocator_type	_alloc;
			key_compare	_key_comp;
			value_compare	_value_comp;

		public :

	/*-----------------------------------------------------------------------------------------*/
	/*                                                                                         */
	/*                                                                                         */
	/*                                    CONSTRUCTORS                                         */
	/*                                                                                         */
	/*                                                                                         */
	/*-----------------------------------------------------------------------------------------*/

			explicit map ( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0), _alloc(alloc), _key_comp(comp), _value_comp(value_compare(comp)) {
				this->_end = this->_alloc.allocate(1);
				this->_end->is_end = true;
				this->_tree = this->_end;
			}

			template <class InputIterator>
			map ( InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0), _alloc(alloc), _key_comp(comp), _value_comp(value_compare(comp)) {
				this->_end = this->_alloc.allocate(1);
				this->_end->is_end = true;
				this->_tree = this->_end;
				while (first != last)
					this->insert(*first++);
			}

			map ( const map & x ) : _alloc(x.get_allocator()), _key_comp(x.key_comp()), _value_comp(x.value_comp()) {
				this = x;
			}

			map & operator=( const map & rhs ) {
				this->clear();
				this->insert(rhs.begin(), rhs.end());
				this->_end = rhs._end;
			}

			~map( void ) {
	
				node*	tmp;
	
				while (this->_tree->left)
				{
					tmp = this->_tree;
					while (tmp->left || tmp->right)
					{
						while (tmp->left)
							tmp = tmp->left;
						if (tmp->right)
							tmp = tmp->right;
					}
					if (tmp == tmp->parent->left)
					{
						tmp = tmp->parent;
						this->_alloc.destroy(tmp->left);
						this->_alloc.deallocate(tmp->left, 1);
						tmp->left = NULL;
					}
					else if (tmp == tmp->parent->right)
					{
						tmp = tmp->parent;
						this->_alloc.destroy(tmp->right);
						this->_alloc.deallocate(tmp->right, 1);
						tmp->right = NULL;
					}
				}
				while (this->_tree->right)
				{
					tmp = this->_tree;
					while (tmp->left || tmp->right)
					{
						while (tmp->right)
							tmp = tmp->right;
						if (tmp->left)
							tmp = tmp->left;
					}
					if (tmp == tmp->parent->left)
					{
						tmp = tmp->parent;
						this->_alloc.destroy(tmp->left);
						this->_alloc.deallocate(tmp->left, 1);
						tmp->left = NULL;
					}
					else if (tmp == tmp->parent->right)
					{
						tmp = tmp->parent;
						this->_alloc.destroy(tmp->right);
						this->_alloc.deallocate(tmp->right, 1);
						tmp->right = NULL;
					}
				}
				this->_alloc.destroy(this->_tree);
				this->_alloc.deallocate(this->_tree, 1);
				this->_alloc.deallocate(this->_end, 1);
			}

	/*-----------------------------------------------------------------------------------------*/
	/*                                                                                         */
	/*                                                                                         */
	/*                                        ITERATOR                                         */
	/*                                                                                         */
	/*                                                                                         */
	/*-----------------------------------------------------------------------------------------*/

			iterator begin( void ) {
				return iterator(this->_first_element());
			}

			const_iterator begin( void ) const {
				return const_iterator(this->_first_element());
			}

			iterator end( void ) {
				return iterator(this->_end);
			}

			const_iterator end( void ) const {
				return const_iterator(this->_end);
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

		private :

			bool _is_equal(const value_type & val1, const value_type & val2) {
				return (!key_compare()(val1.first, val2.first) && !key_compare()(val2.first, val1.first));
			}

			node* _insert( const value_type & val )
			{
				node* to_insert = this->_alloc.allocate(1);
				this->_alloc.construct(to_insert, node(val));
	
				node* x = this->_tree;
				node* x_parent = this->_end;
				if (x != this->_end)
				{
					x_parent = x;
					if (key_compare()(to_insert->root.first, x->root.first))
						x = x->left;
					else
						x = x->right;
				}
				to_insert->parent = x_parent;
				if (x_parent == this->_end)
					this->_tree = to_insert;
				else if (key_compare()(to_insert->root.first, x_parent->root.first))
					x_parent->left = to_insert;
				else
					x_parent->right = to_insert;
				this->_size++;
				return to_insert;
			}

			node* _first_element( void ) {
				if (this->_size == 0)
					return this->_end;
				node*	first = this->_tree;
				while (first && first->left)
					first = first->left;
				return first;
			}

			node* _last_element( void ) {
				if (this->_size == 0)
					return this->_end;
				node* last = this->_tree;
				while (last && last->right)
					last = last->right;
				return last;
			}

			node* _min( node* tree ) {
				while (tree && tree->left)
					tree = tree->left;
				return tree;
			}

			node* _max( node* tree ) {
				while (tree && tree->right)
					tree = tree->right;
				return tree;
			}

		public :

			ft::pair<iterator, bool> insert( const value_type & val ) {

				iterator i = this->begin();
				while (i != this->end() && !this->_is_equal(*i, val))
					i++;

				if (i != this->end() && this->_is_equal(val, *i))
					return (ft::pair<iterator, bool>(i, false));
				else
					return (ft::pair<iterator, bool>(iterator(this->_insert(val)), true));
			}

			iterator insert( iterator position, const value_type& val ) {
				(void)position;
				return (this->insert(val).first);
			}

			template <class InputIterator>
			void insert( InputIterator first, InputIterator last ) {
				for (; first != last; first++)
					this->insert(*first);
			}

			void erase( iterator position ) {

				node* to_erase = position.get_node();
				node* to_erase_son;

				if (!to_erase->left && !to_erase->right) {
					if (to_erase->parent == this->_end)
						this->_tree = this->_end;
					else {
						if (to_erase == to_erase->parent->left)
							to_erase->parent->left = NULL;
						else
							to_erase->parent->right = NULL;
					}
				}
				else if (!to_erase->left || !to_erase->right) {
					if (to_erase->left)
						to_erase_son = to_erase->left;
					else
						to_erase_son = to_erase->right;
					to_erase_son->parent = to_erase->parent;
					if (!to_erase->parent)
						this->_tree = to_erase_son;
					else {
						if (to_erase->parent->left == to_erase)
							to_erase->parent->left = to_erase_son;
						else
							to_erase->parent->right = to_erase_son;
					}
				}
				else {
					node* left_max = this->_max(to_erase->left);
					if (left_max != to_erase->left)
					{
						node* tmp = left_max->left;
						if (tmp)
							left_max->parent->right = tmp;
						tmp->parent = left_max->parent;
					}
					left_max->right = to_erase->right;
					if (left_max->right)
						left_max->right->parent = left_max;
					left_max->parent = to_erase->parent;
					if (left_max->parent != this->_end && left_max->parent->left == to_erase)
						left_max->parent->left = left_max;
					else if (left_max->parent != this->_end && left_max->parent->right == to_erase)
						left_max->parent->right = left_max;
					if (left_max->parent == this->_end)
						this->_tree = left_max;
				}
				this->_alloc.destroy(to_erase);
				this->_alloc.deallocate(to_erase, 1);
				this->_size--;
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
