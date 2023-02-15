#ifndef MAP_HPP
#define MAP_HPP

#include "pair.hpp"
#include "lexicographical_compare.hpp"
#include "node.hpp"
#include "bst_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class map {
		
		public :

			typedef Key									key_type;
			typedef T									mapped_type;
			typedef typename ft::pair<const key_type, mapped_type>				value_type;
			typedef Compare									key_compare;
			typedef s_node<value_type>							node;
			typedef typename Alloc::template rebind<node>::other				allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef typename ft::bst_iterator<node, value_type>				iterator;
			typedef typename ft::const_bst_iterator<node, value_type, iterator>		const_iterator;
			typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type			difference_type;
			typedef size_t									size_type;
			
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
				this->insert(first, last);
			}

			map ( const map & x ) : _size(0), _alloc(x.get_allocator()), _key_comp(x.key_comp()), _value_comp(x.value_comp()) {
				this->_end = this->_alloc.allocate(1);
				this->_end->is_end = true;
				this->_tree = this->_end;
				this->insert(x.begin(), x.end());
			}

			map & operator=( const map & rhs ) {
				this->clear();
				this->insert(rhs.begin(), rhs.end());
				return *this;
			}

			~map( void ) {
	
				if (this->_tree == this->_end)
				{
					this->_alloc.deallocate(this->_tree, 1);
					return ;
				}

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
	/*                                   ELEMENT ACCESS                                        */
	/*                                                                                         */
	/*                                                                                         */
	/*-----------------------------------------------------------------------------------------*/

			mapped_type & operator[]( const key_type & k ) {
				return (this->insert(ft::make_pair(k, mapped_type()))).first->second;
			}

			mapped_type & at( const key_type & k ) {
				iterator it = this->find(k);
				if (it != this->end())
					return it->second;
				else
					throw std::out_of_range("map::at : out of range exception");
			}

			const mapped_type & at( const key_type & k ) const {
				const_iterator it = this->find(k);
				if (it != this->end())
					return it->second;
				else
					throw std::out_of_range("map::at : out of range exception");
			}

	/*-----------------------------------------------------------------------------------------*/
	/*                                                                                         */
	/*                                                                                         */
	/*                                    MODIFIERS                                            */
	/*                                                                                         */
	/*                                                                                         */
	/*-----------------------------------------------------------------------------------------*/

		private :

			bool _is_equal(const key_type & val1, const key_type & val2) const {
				return (!key_compare()(val1, val2) && !key_compare()(val2, val1));
			}

			node* _insert( const value_type & val )
			{
				node* to_insert = this->_alloc.allocate(1);
				this->_alloc.construct(to_insert, node(val));
	
				node* x = this->_tree;
				node* x_parent = this->_end;
				while (x && !x->is_end)
				{
					x_parent = x;
					if (key_compare()(to_insert->root.first, x->root.first))
						x = x->left;
					else
						x = x->right;
				}
				to_insert->parent = x_parent;
				if (x_parent->is_end)
					this->_tree = to_insert;
				else if (key_compare()(to_insert->root.first, x_parent->root.first))
					x_parent->left = to_insert;
				else
					x_parent->right = to_insert;
				this->_size++;
				this->_end->right = this->_last_element();
				return to_insert;
			}

			node* _first_element( void ) const {
				if (this->_size == 0)
					return this->_end;
				node*	first = this->_tree;
				while (first && first->left)
					first = first->left;
				return first;
			}

			node* _last_element( void ) const {
				if (this->_size == 0)
					return this->_end;
				node* last = this->_tree;
				while (last && last->right)
					last = last->right;
				return last;
			}

			node* _min( node* tree ) const {
				while (tree && tree->left)
					tree = tree->left;
				return tree;
			}

			node* _max( node* tree ) const {
				while (tree && tree->right)
					tree = tree->right;
				return tree;
			}

		public :

			ft::pair<iterator, bool> insert( const value_type & val ) {

				iterator i = this->begin();
				while (i != this->end() && !this->_is_equal(i->first, val.first))
					i++;

				if (i != this->end() && this->_is_equal(val.first, i->first))
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
					if (to_erase->parent->is_end)
						this->_tree = this->_end;
					else
					{
						if (to_erase == to_erase->parent->left)
							to_erase->parent->left = NULL;
						else
							to_erase->parent->right = NULL;
					}
				}
				else if (!to_erase->left || !to_erase->right)
				{
					if (to_erase->left)
						to_erase_son = to_erase->left;
					else
						to_erase_son = to_erase->right;
					to_erase_son->parent = to_erase->parent;
					if (to_erase->parent->is_end)
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
						{
							left_max->parent->right = tmp;
							tmp->parent = left_max->parent;
						}
					}
					left_max->right = to_erase->right;
					if (left_max->right)
						left_max->right->parent = left_max;
					left_max->parent = to_erase->parent;
					if (!left_max->parent->is_end && left_max->parent->left == to_erase)
						left_max->parent->left = left_max;
					else if (!left_max->parent->is_end && left_max->parent->right == to_erase)
						left_max->parent->right = left_max;
					if (left_max->parent->is_end)
						this->_tree = left_max;
				}
				this->_alloc.destroy(to_erase);
				this->_alloc.deallocate(to_erase, 1);
				this->_size--;
			}

			iterator erase( iterator first, iterator last ) {
				iterator tmp = first;
				for (; first != last;)
				{
					tmp++;
					this->erase(first);
					first = tmp;
				}
				return last;
			}

			size_type erase( const Key& key ) {
				if (this->count(key))
				{
					iterator it = this->find(key);
					this->erase(it);
					return 1;
				}
				return 0;
			}

			void swap( map & x ) {
				if (*this == x)
					return ;

				node* tmp;

				tmp = x._tree;
				x._tree = this->_tree;
				this->_tree = tmp;

				tmp = x._end;
				x._end = this->_end;
				this->_end = tmp;

				size_type s = x._size;
				x._size = this->_size;
				this->_size = s;
			}

			void clear( void ) {
				
				if (this->_tree->is_end)
					return ;

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
				this->_tree = this->_end;
				this->_size = 0;
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
	/*                                    OPERATIONS                                           */
	/*                                                                                         */
	/*                                                                                         */
	/*-----------------------------------------------------------------------------------------*/

			iterator find( const key_type & k ) {
				node* tmp = this->_tree;
				while (tmp && !tmp->is_end && !this->_is_equal(k, tmp->root.first))
				{
					if (key_compare()(k, tmp->root.first))
						tmp = tmp->left;
					else
						tmp = tmp->right;
				}
				if (!tmp || tmp->is_end)
					return this->end();
				return iterator(tmp);
			}

			const_iterator find( const key_type & k ) const {
				node* tmp = this->_tree;
				while (tmp && !tmp->is_end && !this->_is_equal(k, tmp->root.first))
				{
					if (key_compare()(k, tmp->root.first))
						tmp = tmp->left;
					else
						tmp = tmp->right;
				}
				if (!tmp || tmp->is_end)
					return this->end();
				return const_iterator(tmp);
			}

			size_type count( const key_type & k ) const {
				if (this->find(k) != this->end())
					return 1;
				return 0;
			}

			iterator lower_bound( const key_type & k ) {
				for (iterator find = this->begin(); find != this->end(); find++)
				{
					if (!key_compare()(find->first, k))
						return find;
				}
				return this->end();
			}

			const_iterator lower_bound( const key_type & k ) const {
				for (const_iterator find = this->begin(); find != this->end(); find++)
				{
					if (!key_compare()(find->first, k))
						return const_iterator(find);
				}
				return const_iterator(this->end());
			}

			iterator upper_bound( const key_type & k ) {
				for (iterator find = this->begin(); find != this->end(); find++)
				{
					if (key_compare()(k, find->first))
						return find;
				}
				return this->end();
			}

			const_iterator upper_bound( const key_type & k ) const {
				for (const_iterator find = this->begin(); find != this->end(); find++)
				{
					if (key_compare()(k, find->first))
						return const_iterator(find);
				}
				return const_iterator(this->end());
			}

			ft::pair<const_iterator, const_iterator> equal_range( const key_type & k ) const {
				return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
			}

			ft::pair<iterator, iterator> equal_range( const key_type & k ) {
				return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
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

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		if (lhs.size() != rhs.size())
			return false;
		typename ft::map<Key, T>::const_iterator tmp_l = lhs.begin();
		for (typename ft::map<Key, T>::const_iterator tmp = rhs.begin(); tmp != rhs.end(); tmp++)
		{
			if (*tmp_l != *tmp)
				return false;
			tmp_l++;
		}
		return true;
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (!(operator==(lhs, rhs)));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (!(operator<(lhs, rhs)));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (operator<(rhs, lhs));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (!(operator>(lhs, rhs)));
	}

	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key, T, Compare, Alloc>& lhs, ft::map<Key, T, Compare, Alloc>& rhs ) {
		lhs.swap(rhs);
	}

}

#endif
