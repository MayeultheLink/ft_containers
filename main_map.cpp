#include "enable_if.hpp"
#include "equal.hpp"
#include "is_integral.hpp"
#include "iterator_traits.hpp"
#include "lexicographical_compare.hpp"
#include "make_pair.hpp"
#include "pair.hpp"
#include "random_access_iterator.hpp"
//#include "../bst_iterator.hpp"
#include "map.hpp"

#include <iostream>
#include <iterator>
#include <map>
#include <list>

int main() {

	{
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                             MAP                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << std::endl;




	NAMESPACE::map<int, int> v;

	std::cout << v.size() << " " << v.max_size() << std::endl;

	NAMESPACE::pair<int, int> p(1, 10);
	v.insert(p);

	std::cout << v.size() << " " << v.max_size() << std::endl;

	for (NAMESPACE::map<int, int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << it->first << " ";
	std::cout << std::endl;

	NAMESPACE::pair<int, int> p5(6, 60);
	v.insert(p5);
	for (NAMESPACE::map<int, int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
		std::cout << it->first << " ";
	std::cout << std::endl;

/*
	NAMESPACE::map<int, int> new_v(v);
	for (NAMESPACE::map<int, int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << it->first << " ";
	std::cout << std::endl;
	for (NAMESPACE::map<int, int>::iterator it = new_v.begin(); it != new_v.end(); it++)
		std::cout << it->first << " ";
	std::cout << std::endl;
	if (new_v == v)
		std::cout << "ok" << std::endl;
	NAMESPACE::map<int, int> new_v2;
	new_v2 = v;
	if (new_v2 == v)
		std::cout << "ok" << std::endl;

	ft::pair<int, int> p1(2, 20);
	ft::pair<int, int> p2(3, 30);
	ft::pair<int, int> p3(4, 40);
	v.insert(p1);
	v.insert(p2);
	v.insert(p3);

	std::cout << v[2] << std::endl;
	std::cout << v.at(2) << std::endl;
	std::cout << v.find(3)->first << std::endl;
	std::cout << v.lower_bound(3)->first << std::endl;
	std::cout << std::endl;

	v.insert(v.begin(), p3);
	std::cout << v.size() << " " << v.max_size() << std::endl;
	for (NAMESPACE::map<int, int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << it->first << " ";
	std::cout << std::endl;

	NAMESPACE::map<int, int> v2;
	v.insert(v.begin(), v.end());
	std::cout << v.size() << " " << v.max_size() << std::endl;
	for (NAMESPACE::map<int, int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << it->first << " ";
	std::cout << std::endl;

	NAMESPACE::map<int, int> std_tmp(v);
	std::cout << v.size() << " " << v.max_size() << std::endl;
	for (NAMESPACE::map<int, int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << it->first << " ";
	std::cout << std::endl;

	v.erase(v.begin());
	std::cout << v.size() << " " << v.max_size() << std::endl;
	for (NAMESPACE::map<int, int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << it->first << " ";
	std::cout << std::endl;

	v.erase((v.begin() + 2));
	std::cout << v.size() << " " << v.max_size() << std::endl;
	for (NAMESPACE::map<int, int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << it->first << " ";
	std::cout << std::endl;

	std::cout << v.count(p2) << " " << v.max_size() << std::endl;
	for (NAMESPACE::map<int, int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << it->first << " ";
	std::cout << std::endl;

	v.clear();
	std::cout << v.size() << " " << v.max_size() << std::endl;
	for (NAMESPACE::map<int, int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << it->first << " ";
	std::cout << std::endl;

	std::cout << typeid(v.get_allocator()).name() << std::endl;

*/
	}

	


	return 0;
}
