#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "node.hpp"

namespace ft
{

	template < class T, class U >
	class bst_iterator {

		public:

			typedef typename ft::bidirectional_iterator_tag	iterator_category;
			typedef T					value_type;
			typedef T*					node;
			typedef std::ptrdiff_t				difference_type;
			typedef size_t					size_type;
			typedef U*					pointer;
			typedef U&					reference;
			typedef const pointer				const_pointer;

		private:

			node _node;

		public:

			bst_iterator(void) : _node(NULL) {}
			bst_iterator(const bst_iterator & src) : _node(src.get_node()) {}
			bst_iterator(node n) : _node(n) {}
			~bst_iterator(void) {}

			node get_node(void) const {
				return this->_node;
			}

			T cpy_node(void) const {
				T tmp(this->_node->root);
				tmp.parent = this->_node->parent;
				tmp.left = this->_node->left;
				tmp.right = this->_node->right;
				tmp.is_end = this->_node->is_end;
				return tmp;
			}

			bst_iterator &operator= (const bst_iterator & rhs)
			{
				if (this != &rhs)
					this->_node = rhs._node;
				return *this;
			}

			bst_iterator &operator++ (void)
			{
				this->_node = this->_node->next();
				return *this;
			}

			bst_iterator &operator-- (void)
			{
				if (this->_node->is_end)
					this->_node = this->_node->right;
				else
					this->_node = this->_node->prev();
				return *this;
			}

			bst_iterator operator++ (int)
			{
				bst_iterator tmp = *this;
				this->_node = this->_node->next();
				return tmp;
			}

			bst_iterator operator-- (int)
			{
				bst_iterator tmp = *this;
				if (this->_node->is_end)
					this->_node = this->_node->right;
				else
					this->_node = this->_node->prev();
				return tmp;
			}

			bool operator== (const bst_iterator & rhs) const
			{
				return (this->_node == rhs._node);
			}

			bool operator!= (const bst_iterator &rhs) const
			{
				return this->_node != rhs._node;
			}

			reference operator* (void) const
			{
				return this->_node->root;
			}

			pointer operator-> (void) const
			{
				return &this->_node->root;
			}
	};

	template <class T, class U, class bst_iterator>
	class const_bst_iterator {

		public:

			typedef typename ft::bidirectional_iterator_tag	iterator_category;
			typedef T					value_type;
			typedef T*					node;
			typedef std::ptrdiff_t				difference_type;
			typedef size_t					size_type;
			typedef U*					pointer;
			typedef U&					reference;
			typedef const value_type*			const_pointer;

		private:

			node _node;

		public:

			const_bst_iterator(void) : _node(NULL) {}
			const_bst_iterator(const const_bst_iterator & src) : _node(src.get_node()) {}
			const_bst_iterator(const bst_iterator & src) : _node(src.get_node()) {}
			const_bst_iterator(node n) : _node(n) {}
			~const_bst_iterator(void) {}

			node get_node(void) const {
				return this->_node;
			}

			node cpy_node(void) const {
				node tmp(this->_node->root);
				tmp->parent = this->_node->parent;
				tmp->left = this->_node->left;
				tmp->right = this->_node->right;
				tmp->is_end = this->_node->is_end;
				return tmp;
			}

			const_bst_iterator &operator= (const const_bst_iterator & rhs)
			{
				if (this != &rhs)
					this->_node = rhs._node;
				return *this;
			}

			const_bst_iterator &operator++ (void)
			{
				this->_node = this->_node->next();
				return *this;
			}

			const_bst_iterator &operator-- (void)
			{
				if (this->_node->is_end)
					this->_node = this->_node->right;
				else
					this->_node = this->_node->prev();
				return *this;
			}

			const_bst_iterator operator++ (int)
			{
				const_bst_iterator tmp = *this;
				this->_node = this->_node->next();
				return tmp;
			}

			const_bst_iterator operator-- (int)
			{
				const_bst_iterator tmp = *this;
				if (this->_node->is_end)
					this->_node = this->_node->right;
				else
					this->_node = this->_node->prev();
				return tmp;
			}

			bool operator== (const const_bst_iterator & rhs) const
			{
				return (this->_node == rhs._node);
			}

			bool operator!= (const const_bst_iterator &rhs) const
			{
				return this->_node != rhs._node;
			}

			reference operator* (void) const
			{
				return this->_node->root;
			}

			pointer operator-> (void) const
			{
				return &this->_node->root;
			}
	};

}

#endif
