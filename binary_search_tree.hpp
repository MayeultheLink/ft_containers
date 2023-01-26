#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <iostream>
#include "bst_iterator.hpp"

template< class T >
struct s_node {

	typedef T	value_type;

	s_node*		parent;
	s_node*		left;
	s_node*		right;
	value_type	root;

	s_node( const value_type & val ) : root(val), parent(NULL), left(NULL), right(NULL) {}

};

template< class T, class node = s_node<T>, class Alloc = std::allocator<node> >
class binary_search_tree {

	private :

		node*	_tree;
		Alloc	_alloc;

	public :

		binary_search_tree( void ) : _tree(NULL) {}
		~binary_search_tree( void ) {
			if (!this->_tree)
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
		}

		node* insert( const T & val ) {
			node* to_insert = this->_alloc.allocate(1);
			this->_alloc.construct(to_insert, node(val));
			
			node* x = this->_tree;
			node* x_parent = NULL;
			while (x)
			{
				x_parent = x;
				if (to_insert->root.first < x->root.first)
					x = x->left;
				else
					x = x->right;
			}
			to_insert->parent = x_parent;
			if (!x_parent)
				this->_tree = to_insert;
			else if (to_insert->root.first < x_parent->root.first)
				x_parent->left = to_insert;
			else
				x_parent->right = to_insert;
			return to_insert;
		}

		void print_all( void ) {
			std::cout << "first element : " << this->_tree->root.first << " " << this->_tree->root.second << std::endl;
			std::cout << "left element : " << this->_tree->left->root.first << " " << this->_tree->left->root.second << std::endl;
			std::cout << "right element : " << this->_tree->right->root.first << " " << this->_tree->right->root.second << std::endl;
		}

		node* first_element( void ) {
			node*	first = this->_tree;
			while (first && first->left)
				first = first->left;
			return first;
		}

		node* last_element( void ) {
			node* last = this->_tree;
			while (last && last->right)
				last = last->right;
			return last;
		}

		node* min( node* tree ) {
			while (tree && tree->left)
				tree = tree->left;
			return tree;
		}

		node* max( node* tree ) {
			while (tree && tree->right)
				tree = tree->right;
			return tree;
		}

};

#endif
