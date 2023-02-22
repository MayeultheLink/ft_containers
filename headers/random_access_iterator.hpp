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

			operator random_access_iterator<T const>() const {
				return random_access_iterator<T const>(this->it);
			}

			pointer base() const {
				return this->it;
			}

			bool operator==( const random_access_iterator & src ) const {
				return (this->it == src.base());
			}

			bool operator!=( const random_access_iterator & src ) const {
				return !(operator==(src));
			}

			bool operator>( const random_access_iterator & src ) const {
				return (this->it > src.base());
			}
			
			bool operator>=( const random_access_iterator & src ) const {
				return (this->it >= src.base());
			}
			
			bool operator<( const random_access_iterator & src ) const {
				return (this->it < src.base());
			}
			
			bool operator<=( const random_access_iterator & src ) const {
				return (this->it <= src.base());
			}

			pointer operator->( void ) {
				return (this->it);
			}

			reference operator*( void ) {
				return (*this->it);
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

			random_access_iterator & operator--( void ) {
				--this->it;
				return *this;
			}

			random_access_iterator operator--( int ) {
				random_access_iterator tmp = *this;
				--this->it;
				return tmp;
			}

			random_access_iterator operator+( difference_type n ) const {
				return (this->it + n);
			}

			difference_type operator+( random_access_iterator const & rhs ) const {
				return (this->it + rhs.base());
			}

			random_access_iterator operator-( difference_type n ) const {
				return (this->it - n);
			}

			difference_type operator-( random_access_iterator const & rhs ) const {
				return (this->it - rhs.base());
			}

			random_access_iterator & operator+=( difference_type n ) {
				this->it += n;
				return *this;
			}

			random_access_iterator & operator-=( difference_type n ) {
				this->it -= n;
				return *this;
			}
	
			reference operator[]( difference_type n ) const {
				return *(*this + n);
			}
			

	};

		template <class T>
		ft::random_access_iterator<T> operator+(typename ft::random_access_iterator<T>::difference_type n, ft::random_access_iterator<T> const &rhs)
		{
			return rhs + n;
		}

		template <class T, class U>
		typename ft::random_access_iterator<T>::difference_type operator+( ft::random_access_iterator<T> const & lhs, ft::random_access_iterator<T> const &rhs)
		{
			return rhs.base() + lhs.base();
		}

		template <typename T, typename U>
		typename ft::random_access_iterator<T>::difference_type operator-(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
		{
			return (lhs.base() - rhs.base());
		}

		template <typename Ite1, typename Ite2>
		bool operator==(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs)
		{
			return (lhs.base() == rhs.base());
		}

		template <typename Ite1, typename Ite2>
		bool operator!=(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs)
		{
			return (lhs.base() != rhs.base());
		}

		template <typename Ite1, typename Ite2>
		bool operator<(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs)
		{
			return (lhs.base() < rhs.base());
		}

		template <typename Ite1, typename Ite2>
		bool operator>(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs)
		{
			return (lhs.base() > rhs.base());
		}

		template <typename Ite1, typename Ite2>
		bool operator>=(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs)
		{
			return (lhs.base() >= rhs.base());
		}

		template <typename Ite1, typename Ite2>
		bool operator<=(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs)
		{
			return (lhs.base() <= rhs.base());
		}

}

#endif
