#include "enable_if.hpp"
#include "equal.hpp"
#include "is_integral.hpp"
#include "iterator.hpp"
#include "iterator_traits.hpp"
#include "lexicographical_compare.hpp"
#include "make_pair.hpp"
#include "pair.hpp"
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "vector.hpp"

#include <iostream>
#include <iterator>
#include <vector>

class A {};

template< class T >
void ft_f(T) {}
//typename ft::enable_if<std::is_trivially_copyable<T>::value>::type ft_f(T) {}
template< class T >
void std_f(T) {}
//typename std::enable_if<std::is_trivially_copyable<T>::value>::type std_f(T) {}

int main() {

	{
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                           ENABLE IF                         */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << std::endl;

	ft_f(3);
	std_f(3);
	std::vector<int> tmp;
	ft_f(tmp);
	std_f(tmp);

	std::cout << "ok" << std::endl;

	std::cout << std::endl;
	}

	{
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                             EQUAL                           */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << std::endl;

	std::vector<int> tmp;
	std::vector<int> tmp2;
	for (int i = 0; i < 10; i++)
		tmp.push_back(i);
	for (int i = 0; i < 10; i++)
		tmp2.push_back(i);
	if (ft::equal(tmp.begin(), tmp.end(), tmp2.begin()) == std::equal(tmp.begin(), tmp.end(), tmp2.begin()))
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;

	for (int i = 0; i < 10; i++)
		tmp2.push_back(i);
	if (ft::equal(tmp.begin(), tmp.end(), tmp2.begin()) == std::equal(tmp.begin(), tmp.end(), tmp2.begin()))
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;

	std::cout << std::endl;
	}

	{
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                  LEXICOGRAPHICAL COMPARE                    */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << std::endl;

	std::vector<int> tmp;
	std::vector<int> tmp2;
	for (int i = 0; i < 10; i++)
		tmp.push_back(i);
	for (int i = 0; i < 10; i++)
		tmp2.push_back(i);
	if (ft::lexicographical_compare(tmp.begin(), tmp.end(), tmp2.begin(), tmp2.end()) == std::lexicographical_compare(tmp.begin(), tmp.end(), tmp2.begin(), tmp2.end()))
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;

	for (int i = 0; i < 10; i++)
		tmp2.push_back(i);
	tmp.insert(tmp.begin(), 1);
	if (ft::lexicographical_compare(tmp.begin(), tmp.end(), tmp2.begin(), tmp2.end()) == std::lexicographical_compare(tmp.begin(), tmp.end(), tmp2.begin(), tmp2.end()))
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;

	std::cout << std::endl;
	}

	{
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                         IS_INTEGRAL                         */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << std::endl;

	if (ft::is_integral<int>::value == std::is_integral<int>::value)
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;
	
	if (ft::is_integral<const bool>::value == std::is_integral<const bool>::value)
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;
	
	if (ft::is_integral<wchar_t>::value == std::is_integral<wchar_t>::value)
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;
	
	if (ft::is_integral<volatile unsigned long long int>::value == std::is_integral<volatile unsigned long long int>::value)
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;
	
	if (ft::is_integral<std::vector<int> >::value == std::is_integral<std::vector<int> >::value)
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;
	
	if (ft::is_integral<A>::value == std::is_integral<A>::value)
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;
	
	std::cout << std::endl;
	}

	{
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                       ITERATOR TRAITS                       */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << std::endl;

	if (typeid(ft::iterator_traits<std::vector<int>::iterator>::difference_type) == typeid(std::iterator_traits<std::vector<int>::iterator>::difference_type))
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;

	if (typeid(ft::iterator_traits<std::vector<int>::iterator>::value_type) == typeid(std::iterator_traits<std::vector<int>::iterator>::value_type))
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;

	if (typeid(ft::iterator_traits<std::vector<int>::iterator>::pointer) == typeid(std::iterator_traits<std::vector<int>::iterator>::pointer))
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;

	if (typeid(ft::iterator_traits<std::vector<const int*>::iterator>::reference) == typeid(std::iterator_traits<std::vector<const int*>::iterator>::reference))
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;

	if (typeid(ft::iterator_traits<std::vector<int*>::iterator>::iterator_category) == typeid(std::iterator_traits<std::vector<int*>::iterator>::iterator_category))
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;

	std::cout << std::endl;
	}

	{
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                             PAIR                            */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << std::endl;

	ft::pair<int, char> ft_p1(42, 'c');
	ft::pair<int, char> ft_p2(42, 'c');
	if (ft_p1 == ft_p2)
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;

	ft_p1.first = 43;
	if (ft_p1 == ft_p2)
		std::cout << "error" << std::endl;
	else
		std::cout << "ok" << std::endl;

	if (ft_p1 < ft_p2)
		std::cout << "error" << std::endl;
	else
		std::cout << "ok" << std::endl;


	std::cout << std::endl;
	}

	{
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                         MAKE PAIR                           */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << std::endl;

	ft::pair<int, char> ft_p;
	ft_p = ft::make_pair(42, 'c');
	if (ft_p.first == 42 && ft_p.second == 'c')
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;

	std::cout << std::endl;
	}

	{
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                       REVERSE ITERATOR                      */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << std::endl;

	if (typeid(ft::reverse_iterator<std::vector<int>::iterator>::difference_type) == typeid(std::reverse_iterator<std::vector<int>::iterator>::difference_type))
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;

	if (typeid(ft::reverse_iterator<std::vector<int>::iterator>::value_type) == typeid(std::reverse_iterator<std::vector<int>::iterator>::value_type))
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;

	if (typeid(ft::reverse_iterator<std::vector<int>::iterator>::pointer) == typeid(std::reverse_iterator<std::vector<int>::iterator>::pointer))
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;

	if (typeid(ft::reverse_iterator<std::vector<const int*>::iterator>::reference) == typeid(std::reverse_iterator<std::vector<const int*>::iterator>::reference))
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;

	if (typeid(ft::reverse_iterator<std::vector<int*>::iterator>::iterator_category) == typeid(std::reverse_iterator<std::vector<int*>::iterator>::iterator_category))
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;

	std::cout << std::endl;
	}

	{
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                            VECTOR                           */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << std::endl;

	std::vector<int> std_v;
	ft::vector<int> ft_v;

	std::cout << "std : " << std_v.size() << " " << std_v.max_size() << " " << std_v.capacity() << std::endl;
	std::cout << "ft  : " << ft_v.size() << " " << ft_v.max_size() << " " << ft_v.capacity() << std::endl;

	if (std_v.empty() == ft_v.empty())
		std::cout << "ok" << std::endl;

	for(int i = 0; i < 10; i++)
	{
		std_v.push_back(i);
		ft_v.push_back(i);
	}

	std::cout << "std : " << std_v.size() << " " << std_v.max_size() << " " << std_v.capacity() << std::endl;
	std::cout << "ft  : " << ft_v.size() << " " << ft_v.max_size() << " " << ft_v.capacity() << std::endl;

	if (std_v.empty() == ft_v.empty())
		std::cout << "ok" << std::endl;

	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	for (ft::vector<int>::reverse_iterator it = ft_v.rbegin(); it != ft_v.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	for (std::vector<int>::reverse_iterator it = std_v.rbegin(); it != std_v.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	ft::vector<int> new_v(ft_v);
	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = new_v.begin(); it != new_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	if (new_v == ft_v)
		std::cout << "ok" << std::endl;
	ft::vector<int> new_v2;
	new_v2 = ft_v;
	if (new_v2 == ft_v)
		std::cout << "ok" << std::endl;

	ft_v.resize(11);
	std_v.resize(11);
	std::cout << "std : " << std_v.size() << " " << std_v.max_size() << " " << std_v.capacity() << std::endl;
	std::cout << "ft  : " << ft_v.size() << " " << ft_v.max_size() << " " << ft_v.capacity() << std::endl;
	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	ft_v.resize(5);
	std_v.resize(5);
	std::cout << "std : " << std_v.size() << " " << std_v.max_size() << " " << std_v.capacity() << std::endl;
	std::cout << "ft  : " << ft_v.size() << " " << ft_v.max_size() << " " << ft_v.capacity() << std::endl;
	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	ft_v.reserve(50);
	std_v.reserve(50);
	std::cout << "std : " << std_v.size() << " " << std_v.max_size() << " " << std_v.capacity() << std::endl;
	std::cout << "ft  : " << ft_v.size() << " " << ft_v.max_size() << " " << ft_v.capacity() << std::endl;
	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "std : " << std_v[2] << std::endl;
	std::cout << "ft  : " << ft_v[2] << std::endl;
	//std::cout << "std : " << std_v[8] << std::endl;
	//std::cout << "ft  : " << ft_v[8] << std::endl;
	std::cout << "std : " << std_v.at(2) << std::endl;
	std::cout << "ft  : " << ft_v.at(2) << std::endl;
	//std::cout << "std : " << std_v.at(8) << std::endl;
	//std::cout << "ft  : " << ft_v.at(8) << std::endl;
	std::cout << "std : " << std_v.front() << std::endl;
	std::cout << "ft  : " << ft_v.front() << std::endl;
	std::cout << "std : " << std_v.back() << std::endl;
	std::cout << "ft  : " << ft_v.back() << std::endl;
	std::cout << "std : " << *std_v.data() << std::endl;
	std::cout << "ft  : " << *ft_v.data() << std::endl;
	std::cout << std::endl;

	std_v.assign(7, 1);
	ft_v.assign(7, 1);
	std::cout << "std : " << std_v.size() << " " << std_v.max_size() << " " << std_v.capacity() << std::endl;
	std::cout << "ft  : " << ft_v.size() << " " << ft_v.max_size() << " " << ft_v.capacity() << std::endl;
	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::vector<int> new_std_v;
	ft::vector<int> new_ft_v;
	for (int i = 26; i < 50; i += 2)
	{
		new_std_v.push_back(i);
		new_ft_v.push_back(i);
	}
	std_v.assign(new_std_v.begin(), new_std_v.end());
	ft_v.assign(new_ft_v.begin(), new_ft_v.end());
	std::cout << "std : " << std_v.size() << " " << std_v.max_size() << " " << std_v.capacity() << std::endl;
	std::cout << "ft  : " << ft_v.size() << " " << ft_v.max_size() << " " << ft_v.capacity() << std::endl;
	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std_v.pop_back();
	ft_v.pop_back();

	std::cout << "std : " << std_v.size() << " " << std_v.max_size() << " " << std_v.capacity() << std::endl;
	std::cout << "ft  : " << ft_v.size() << " " << ft_v.max_size() << " " << ft_v.capacity() << std::endl;
	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std_v.pop_back();
	ft_v.pop_back();
	std_v.pop_back();
	ft_v.pop_back();
	std_v.pop_back();
	ft_v.pop_back();
	std_v.pop_back();
	ft_v.pop_back();
	std_v.pop_back();
	ft_v.pop_back();
	std_v.pop_back();
	ft_v.pop_back();
	std_v.pop_back();
	ft_v.pop_back();
	std_v.pop_back();
	ft_v.pop_back();
	std_v.pop_back();
	ft_v.pop_back();
	std_v.pop_back();
	ft_v.pop_back();
	std_v.pop_back();
	ft_v.pop_back();
	std::cout << "std : " << std_v.size() << " " << std_v.max_size() << " " << std_v.capacity() << std::endl;
	std::cout << "ft  : " << ft_v.size() << " " << ft_v.max_size() << " " << ft_v.capacity() << std::endl;
	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std_v.insert(std_v.begin(), 42);
	ft_v.insert(ft_v.begin(), 42);
	std::cout << "std : " << std_v.size() << " " << std_v.max_size() << " " << std_v.capacity() << std::endl;
	std::cout << "ft  : " << ft_v.size() << " " << ft_v.max_size() << " " << ft_v.capacity() << std::endl;
	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std_v.insert(std_v.begin(), 4, 2);
	ft_v.insert(ft_v.begin(), 4, 2);
	std::cout << "std : " << std_v.size() << " " << std_v.max_size() << " " << std_v.capacity() << std::endl;
	std::cout << "ft  : " << ft_v.size() << " " << ft_v.max_size() << " " << ft_v.capacity() << std::endl;
	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::vector<int> std_tmp;
	ft::vector<int> ft_tmp;
	for (int i = 0; i < 5; i++)
	{
		std_tmp.push_back(i);
		ft_tmp.push_back(i);
	}
	std_v.insert(std_v.begin(), std_tmp.begin(), std_tmp.end());
	ft_v.insert(ft_v.begin(), ft_tmp.begin(), ft_tmp.end());
	std::cout << "std : " << std_v.size() << " " << std_v.max_size() << " " << std_v.capacity() << std::endl;
	std::cout << "ft  : " << ft_v.size() << " " << ft_v.max_size() << " " << ft_v.capacity() << std::endl;
	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std_v.erase(std_v.begin());
	ft_v.erase(ft_v.begin());
	std::cout << "std : " << std_v.size() << " " << std_v.max_size() << " " << std_v.capacity() << std::endl;
	std::cout << "ft  : " << ft_v.size() << " " << ft_v.max_size() << " " << ft_v.capacity() << std::endl;
	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std_v.erase(std_v.begin(), (std_v.begin() + 2));
	ft_v.erase(ft_v.begin(), (ft_v.begin() + 2));
	std::cout << "std : " << std_v.size() << " " << std_v.max_size() << " " << std_v.capacity() << std::endl;
	std::cout << "ft  : " << ft_v.size() << " " << ft_v.max_size() << " " << ft_v.capacity() << std::endl;
	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std_v.swap(std_tmp);
	ft_v.swap(ft_tmp);
	std::cout << "std : " << std_v.size() << " " << std_v.max_size() << " " << std_v.capacity() << std::endl;
	std::cout << "ft  : " << ft_v.size() << " " << ft_v.max_size() << " " << ft_v.capacity() << std::endl;
	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std_v.clear();
	ft_v.clear();
	std::cout << "std : " << std_v.size() << " " << std_v.max_size() << " " << std_v.capacity() << std::endl;
	std::cout << "ft  : " << ft_v.size() << " " << ft_v.max_size() << " " << ft_v.capacity() << std::endl;
	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "std : " << typeid(std_v.get_allocator()).name() << std::endl;
	std::cout << "ft : " << typeid(ft_v.get_allocator()).name() << std::endl;

	std::swap(std_tmp, std_v);
	ft::swap(ft_tmp, ft_v);
	std::cout << "std : " << std_v.size() << " " << std_v.max_size() << " " << std_v.capacity() << std::endl;
	std::cout << "ft  : " << ft_v.size() << " " << ft_v.max_size() << " " << ft_v.capacity() << std::endl;
	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	ft_tmp = ft_v;
	if (ft_tmp == ft_v)
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;
	ft_v.push_back(42);
	if (ft_tmp != ft_v)
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;
	if (ft_tmp < ft_v)
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;
	if (ft_tmp <= ft_v)
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;
	ft_tmp.push_back(43);
	if (ft_tmp > ft_v)
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;
	if (ft_tmp >= ft_v)
		std::cout << "ok" << std::endl;
	else
		std::cout << "error" << std::endl;


	std::cout << std::endl;
	}


	return 0;
}
