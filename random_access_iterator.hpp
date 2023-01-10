#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

namespace ft {

	template< typename T >
	class random_access_iterator {
	
		public :

			typedef typename ft::random_access_iterator_tag	iterator_category;
			typedef T					value_type;
			typedef std::ptrdiff_t				difference_type;
			typedef size_t					size_type;
			typedef T*					pointer;
			typedef T&					reference;
			typedef const T*				const_pointer;
			typedef const T&				const_reference;

		private :

			pointer	it;

		public:

			random_access_iterator( void ) : it(NULL) {}
			random_access_iterator( pointer it ) : it(it) {}
			random_access_iterator( const random_access_iterator<T> & src ) : it(src.base()) {}
			~random_access_iterator( void ) {}

			random_access_iterator & operator=( random_access_iterator<T> const & cpy ) {
				this->it = cpy.base();
				return *this;
			}

			pointer base() const {
				return this->it;
			}

			reference operator*( void ) const {
				return (*(this->it));
			}

			random_access_iterator operator+( difference_type n ) const {
				random_access_iterator tmp = *this;
				tmp->it += n;
				return tmp;
			}

			difference_type operator+( random_access_iterator const & rhs ) const {
				return (this->it + rhs.base());
			}

			difference_type operator-( random_access_iterator const & rhs ) const {
				return (this->it - rhs.base());
			}

			random_access_iterator & operator++( void ) {
				this->it++;
				return *this;
			}

			random_access_iterator operator++( int ) {
				random_access_iterator tmp = *this;
				++this->it;
				return tmp;
			}

			random_access_iterator & operator+=( difference_type n ) {
				this->it += n;
				return *this;
			}

			random_access_iterator operator-( difference_type n ) const {
				random_access_iterator tmp = *this;
				tmp->it -= n;
				return tmp;
			}

			random_access_iterator & operator--( void ) {
				--this->it;
				return *this;
			}

			random_access_iterator operator--( int ) {
				random_access_iterator tmp = *this;
				--this->it;
				return tmp;
			}

			random_access_iterator & operator-=( difference_type n ) {
				this->it -= n;
				return *this;
			}
	
			pointer operator->( void ) const {
				return &(operator*());
			}

			reference operator[]( difference_type n ) const {
				return *(*this + n);
			}

	};

	template< class T >
	bool operator==( const random_access_iterator<T> & lhs, const random_access_iterator<T> & rhs ) {
		if (lhs.base() == rhs.base())
			return true;
		return false;
	}

	template< class T >
	bool operator!=( const random_access_iterator<T> & lhs, const random_access_iterator<T> & rhs ) {
		if (lhs.base() != rhs.base())
			return true;
		return false;
	}

	template< class T >
	bool operator<( const random_access_iterator<T> & lhs, const random_access_iterator<T> & rhs ) {
		if (lhs.base() > rhs.base())
			return true;
		return false;
	}

	template< class T >
	bool operator<=( const random_access_iterator<T> & lhs, const random_access_iterator<T> & rhs ) {
		if (lhs.base() >= rhs.base())
			return true;
		return false;
	}

	template< class T >
	bool operator>( const random_access_iterator<T> & lhs, const random_access_iterator<T> & rhs ) {
		if (lhs.base() < rhs.base())
			return true;
		return false;
	}

	template< class T >
	bool operator>=( const random_access_iterator<T> & lhs, const random_access_iterator<T> & rhs ) {
		if (lhs.base() <= rhs.base())
			return true;
		return false;
	}

	template <class T>
	random_access_iterator<T> operator+( typename random_access_iterator<T>::difference_type n, const random_access_iterator<T> & rhs) {
		return (rhs + n);
	}

	template <class T>
	random_access_iterator<T> operator-( typename random_access_iterator<T>::difference_type n, const random_access_iterator<T> & rhs) {
		return (rhs - n);
	}

}

#endif
