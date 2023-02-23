#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "node.hpp"

namespace ft
{

	template < class T >
	class const_bst_iterator;

	template < class T >
	class bst_iterator {

		public:

			typedef typename ft::bidirectional_iterator_tag		iterator_category;
			typedef T						value_type;
			typedef T*						pointer;
			typedef T&						reference;
			typedef s_node<T>*					node;
			typedef typename iterator_traits<node>::difference_type	difference_type;

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

			bst_iterator &operator= (const bst_iterator & rhs)
			{
				if (*this != rhs)
					this->_node = rhs.get_node();
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

			template < class U >
			bool operator== (const const_bst_iterator<U> & rhs) const
			{
				return (this->_node == rhs.get_node());
			}

			template < class U >
			bool operator!= (const const_bst_iterator<U> &rhs) const
			{
				return this->_node != rhs.get_node();
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

	template < class T >
	class const_bst_iterator {

		public:

			typedef typename ft::bidirectional_iterator_tag		iterator_category;
			typedef T						value_type;
			typedef const T*					pointer;
			typedef const T&					reference;
			typedef s_node<T>*					node;
			typedef typename iterator_traits<node>::difference_type	difference_type;

		private:

			node _node;

		public:

			const_bst_iterator(void) : _node(NULL) {}
			template <class U>
			const_bst_iterator(const bst_iterator<U> & src) : _node(src.get_node()) {}
			const_bst_iterator(node n) : _node(n) {}
			~const_bst_iterator(void) {}

			node get_node(void) const {
				return this->_node;
			}

			template <class U>
			const_bst_iterator &operator= (const bst_iterator<U> & rhs)
			{
				if (*this != rhs)
					this->_node = rhs.get_node();
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

			template < class U >
			bool operator== (const bst_iterator<U> & rhs) const
			{
				return (this->_node == rhs.get_node());
			}

			template < class U >
			bool operator!= (const bst_iterator<U> &rhs) const
			{
				return this->_node != rhs.get_node();
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
