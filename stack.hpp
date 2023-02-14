#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft {

	template< class T, class Container = ft::vector<T> >
	class stack {
		
		public :
			
			typedef Container				container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;

		private :

			container_type	_c;

		public :

			explicit stack( void ) {}
			stack( const stack& other ) : _c(other._c) {}
			stack( const container_type& other ) : _c(other) {}
			~stack() {}
			stack& operator=( const stack& other ) {
				this->_c = other._c;
				return *this;
			}

			reference top() {
				return this->_c.back();
			}
			const_reference top() const {
				this->_c.back();
			}

			bool empty() const {
				return this->_c.empty();
			}

			size_type size() const {
				return this->_c.size();
			}

			void push( const value_type& value ) {
				this->_c.push_back(value);
			}

			void pop() {
				this->_c.pop_back();
			}

			template<typename _T, typename _c>
			friend bool operator==( const stack<_T, _c>& lhs, const stack<_T, _c>& rhs );
			template<typename _T, typename _c>
			friend bool operator!=( const stack<_T, _c>& lhs, const stack<_T, _c>& rhs );
			template<typename _T, typename _c>
			friend bool operator<( const stack<_T, _c>& lhs, const stack<_T, _c>& rhs );
			template<typename _T, typename _c>
			friend bool operator<=( const stack<_T, _c>& lhs, const stack<_T, _c>& rhs );
			template<typename _T, typename _c>
			friend bool operator>( const stack<_T, _c>& lhs, const stack<_T, _c>& rhs );
			template<typename _T, typename _c>
			friend bool operator>=( const stack<_T, _c>& lhs, const stack<_T, _c>& rhs );

	};

	template< class T, class Container >
	bool operator==( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) {
		return (lhs._c == rhs._c);
	}

	template< class T, class Container >
	bool operator!=( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) {
		return (lhs._c != rhs._c);
	}

	template< class T, class Container >
	bool operator< ( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) {
		return (lhs._c < rhs._c);
	}

	template< class T, class Container >
	bool operator<= ( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) {
		return (lhs._c <= rhs._c);
	}

	template< class T, class Container >
	bool operator> ( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) {
		return (lhs._c > rhs._c);
	}

	template< class T, class Container >
	bool operator>= ( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) {
		return (lhs._c >= rhs._c);
	}

}

#endif
