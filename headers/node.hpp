#ifndef NODE_HPP
#define NODE_HPP

template< class value_type >
struct s_node {

	s_node*		parent;
	s_node*		left;
	s_node*		right;
	value_type	root;
	bool		is_end;

	s_node( const value_type & val ) : parent(0), left(0), right(0), root(val), is_end(false) {}

	s_node*	next( void ) {
		s_node* tmp = this;
		if (tmp->right)
		{
			tmp = tmp->right;
			while (tmp->left)
				tmp = tmp->left;
			return tmp;
		}
		else
		{
			s_node* tmp_parent = tmp->parent;
			while (!tmp_parent->is_end && tmp == tmp_parent->right)
			{
				tmp = tmp_parent;
				tmp_parent = tmp_parent->parent;
			}
			return tmp_parent;
		}
	}

	s_node* prev( void ) {
		s_node* tmp = this;
		if (!tmp->is_end && tmp->left)
		{
			tmp = tmp->left;
			while (tmp->right)
				tmp = tmp->right;
		}
		else if (!tmp->is_end)
		{
			s_node* tmp_parent = tmp->parent;
			while (!tmp_parent->is_end && tmp == tmp_parent->left)
			{
				tmp = tmp_parent;
				tmp_parent = tmp_parent->parent;
			}
			return tmp_parent;
		}
		return tmp;
	}

};

#endif
