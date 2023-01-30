#ifndef BST_ITERATOR_HPP
#define BST_ITERATOR_HPP

#include "pair.hpp"
#include "map.hpp"
#include "node.hpp"

#include <algorithm>

namespace ft {

	template< typename T >
	class bst_iterator {
	
		public :

			typedef typename ft::bidirectional_iterator_tag	iterator_category;
			typedef T					value_type;
			typedef std::ptrdiff_t				difference_type;
			typedef size_t					size_type;
			typedef T*					pointer;
			typedef T&					reference;
			typedef const T*				const_pointer;
			typedef const T&				const_reference;

		private :

			s_node<value_type>*	_node;

		public:

			bst_iterator( void ) : _node(NULL) {}
			bst_iterator( s_node<value_type>* n ) : _node(n) {}
			bst_iterator( const bst_iterator<T> & src ) {
				this->_node = src._node;
			}
			~bst_iterator( void ) {}

			s_node<value_type>* get_node( void ) {
				return this->_node;
			}

			bst_iterator & operator=( bst_iterator<T> const & cpy ) {
				this->_node = cpy._node;
				return *this;
			}

			bool operator==( const bst_iterator & src ) const {
				return (this->_node == src._node);
			}

			bool operator!=( const bst_iterator & src ) const {
				return !(operator==(src));
			}

			pointer operator->( void ) {
				return (&this->_node->root);
			}

			reference operator*( void ) {
				return (this->_node->root);
			}
			
			bst_iterator & operator++( void ) {
				s_node<value_type>* tmp = this->_node->right;
				if (tmp)
				{
					while (tmp->left)
						tmp = tmp->left;
					this->_node = tmp;
				}
				else
				{
					s_node<value_type>* parent;
					tmp = this->_node;
					parent = this->_node->parent;
					while (!parent->is_end && tmp == parent->right)
					{
						tmp = parent;
						parent = tmp->parent;
					}
					this->_node = parent;
				}

				return *this;
			}

			bst_iterator operator++( int ) {
				bst_iterator ret = *this;
				s_node<value_type>* tmp = this->_node->right;
				if (tmp)
				{
					while (tmp->left)
						tmp = tmp->left;
					this->_node = tmp;
				}
				else
				{
					s_node<value_type>* parent;
					tmp = this->_node;
					parent = this->_node->parent;
					while (!parent->is_end && tmp == parent->right)
					{
						tmp = parent;
						parent = tmp->parent;
					}
					this->_node = parent;
				}

				return ret;
			}

			bst_iterator & operator--( void ) {
				--this->it;
				return *this;
			}

			bst_iterator operator--( int ) {
				bst_iterator tmp = *this;
				--this->it;
				return tmp;
			}

	};

		template <typename Ite1, typename Ite2>
		bool operator==(const bst_iterator<Ite1> &lhs, const bst_iterator<Ite2> &rhs)
		{
			return (lhs.base() == rhs.base());
		}

		template <typename Ite1, typename Ite2>
		bool operator!=(const bst_iterator<Ite1> &lhs, const bst_iterator<Ite2> &rhs)
		{
			return (lhs.base() != rhs.base());
		}

}

#endif
