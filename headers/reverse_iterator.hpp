#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

	template< typename Iter >
	class reverse_iterator {
	
		private :

			Iter	it;

		public :

			typedef Iter							iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type		value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type	difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer		pointer;
			typedef typename ft::iterator_traits<Iter>::reference		reference;

			reverse_iterator( void ) : it(NULL) {}
			explicit reverse_iterator( Iter it ) : it(it) {}
			template< class T >
			reverse_iterator( const reverse_iterator<T> & src ) : it(src.base()) {}
			template< class T >
			reverse_iterator & operator=( const reverse_iterator<T> & rhs ) {
				this->it = rhs.base();
				return *this;
			}
			~reverse_iterator() {}

			Iter base() const {
				return this->it;
			}

			reference operator*( void ) const {
				Iter tmp = this->it;
				return (*--tmp);
			}

			reverse_iterator operator+( difference_type n ) const {
				Iter tmp = this->it;
				tmp -= n;
				reverse_iterator ret(tmp);
				return ret;
			}

			reverse_iterator & operator++( void ) {
				--this->it;
				return *this;
			}

			reverse_iterator operator++( int ) {
				reverse_iterator tmp = *this;
				--this->it;
				return tmp;
			}

			reverse_iterator & operator+=( difference_type n ) {
				this->it -= n;
				return *this;
			}

			reverse_iterator operator-( difference_type n ) const {
				Iter tmp = this->it;
				tmp += n;
				reverse_iterator ret(tmp);
				return ret;
			}

			reverse_iterator & operator--( void ) {
				++this->it;
				return *this;
			}

			reverse_iterator operator--( int ) {
				reverse_iterator tmp = *this;
				++this->it;
				return tmp;
			}

			reverse_iterator & operator-=( difference_type n ) {
				this->it += n;
				return *this;
			}
	
			pointer operator->( void ) const {
				return &(operator*());
			}

			reference operator[]( difference_type n ) const {
				return *(*this + n);
			}

	};

	template< class Iter1, class Iter2 >
	bool operator==( const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs ) {
		if (lhs.base() == rhs.base())
			return true;
		return false;
	}

	template< class Iter1, class Iter2 >
	bool operator!=( const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs ) {
		if (lhs.base() != rhs.base())
			return true;
		return false;
	}

	template< class Iter1, class Iter2 >
	bool operator<( const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs ) {
		if (lhs.base() > rhs.base())
			return true;
		return false;
	}

	template< class Iter1, class Iter2 >
	bool operator<=( const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs ) {
		if (lhs.base() >= rhs.base())
			return true;
		return false;
	}

	template< class Iter1, class Iter2 >
	bool operator>( const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs ) {
		if (lhs.base() < rhs.base())
			return true;
		return false;
	}

	template< class Iter1, class Iter2 >
	bool operator>=( const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs ) {
		if (lhs.base() <= rhs.base())
			return true;
		return false;
	}

	template <class Iter>
	reverse_iterator<Iter> operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> & rhs) {
		return (rhs + n);
	}

	template <class Iter1, class Iter2>
	typename ft::reverse_iterator<Iter1>::difference_type operator+( const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs) {
		return (rhs.base() + lhs.base());
	}

	template <class Iter>
	reverse_iterator<Iter> operator-( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> & rhs) {
		return (rhs - n);
	}

	template <class Iter1, class Iter2>
	typename ft::reverse_iterator<Iter1>::difference_type operator-( const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs) {
		return (rhs.base() - lhs.base());
	}

}

#endif
