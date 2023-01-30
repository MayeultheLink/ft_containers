#ifndef NODE_HPP
#define NODE_HPP

template< class value_type >
struct s_node {

	s_node*		parent;
	s_node*		left;
	s_node*		right;
	value_type	root;
	bool		is_end;

	s_node( const value_type & val ) : root(val), parent(NULL), left(NULL), right(NULL), is_end(false) {}

};

#endif
