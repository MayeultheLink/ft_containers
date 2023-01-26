#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {

	template< class T1, class T2 >
	class pair {
	
		public :

			pair( void ) : first(T1()), second(T2()) {};
			pair( const T1 & x, const T2 & y ) : first(x), second(y) {};
			template< class U1, class U2 >
			pair( const pair<U1, U2> & p ) : first(p.first), second(p.second) {};
			pair & operator=( const pair & p ) {
				this->first = p.first;
				this->second = p.second;
				return *this;
			};

			T1 first;
			T2 second;

	};

}

template< class T1, class T2 >
bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
	if (lhs.first == rhs.first && lhs.second == rhs.second)
		return true;
	return false;
};

template< class T1, class T2 >
bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
	return !(lhs == rhs);
};

template< class T1, class T2 >
bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
	if (lhs.first < rhs.first)
		return true;
	if (rhs.first < lhs.first)
		return false;
	if (lhs.second < rhs.second)
		return true;
	return false;
};

template< class T1, class T2 >
bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
	return !(rhs < lhs);
};

template< class T1, class T2 >
bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
	return (rhs < lhs);
};

template< class T1, class T2 >
bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
	return !(lhs < rhs);
};

#endif
