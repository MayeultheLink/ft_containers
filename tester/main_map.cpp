#include "../enable_if.hpp"
#include "../equal.hpp"
#include "../is_integral.hpp"
#include "../iterator_traits.hpp"
#include "../lexicographical_compare.hpp"
#include "../make_pair.hpp"
#include "../pair.hpp"
#include "../random_access_iterator.hpp"
//#include "../bst_iterator.hpp"
#include "../map.hpp"

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

	for (int i = 0; i < 5000; i++)
		v[i] = i * 10;

	std::cout << v.size() << " " << v.max_size() << std::endl;

	NAMESPACE::map<int, int>::const_iterator it;
      	it = v.begin();
	for (; it != v.end(); it++)
		std::cout << "1 : " << it->first << " ";
	std::cout << std::endl;

	NAMESPACE::pair<int, int> p9(9, 90);
	v.insert(p9);

	for (NAMESPACE::map<int, int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
		std::cout << "2 : " << it->first << " ";
	std::cout << std::endl;

	NAMESPACE::map<int, int> new_v(v);
	for (NAMESPACE::map<int, int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << "3 : " << it->first << " ";
	std::cout << std::endl;
	for (NAMESPACE::map<int, int>::iterator it = new_v.begin(); it != new_v.end(); it++)
		std::cout << "4 : " << it->first << " ";
	std::cout << std::endl;
	if (new_v == v)
		std::cout << "ok" << std::endl;
	NAMESPACE::map<int, int> new_v2;
	new_v2 = v;
	if (new_v2 == v)
		std::cout << "ok" << std::endl;

	NAMESPACE::pair<int, int> p1(2, 20);
	NAMESPACE::pair<int, int> p2(3, 30);
	NAMESPACE::pair<int, int> p3(4, 40);
	v.insert(p1);
	v.insert(p2);
	v.insert(p3);

	v.erase(--(--(v.end())), --v.end());

	std::cout << v[2] << std::endl;
	std::cout << v.at(2) << std::endl;
	std::cout << v.find(3)->first << std::endl;
	std::cout << v.lower_bound(3)->first << std::endl;
	std::cout << std::endl;

	v.insert(v.begin(), p3);
	std::cout << v.size() << " " << v.max_size() << std::endl;
	for (NAMESPACE::map<int, int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << "5 : " << it->first << " ";
	std::cout << std::endl;

	NAMESPACE::map<int, int> v2;
	v2.insert(v.begin(), v.end());
	std::cout << v2.size() << " " << v2.max_size() << std::endl;
	for (NAMESPACE::map<int, int>::iterator it = v2.begin(); it != v2.end(); it++)
		std::cout << "6 : " << it->first << " ";
	std::cout << std::endl;

	NAMESPACE::map<int, int> std_tmp(v);
	std::cout << v.size() << " " << v.max_size() << std::endl;
	for (NAMESPACE::map<int, int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << "7 : " << it->first << " ";
	std::cout << std::endl;

	v.erase(v.begin());
	std::cout << v.size() << " " << v.max_size() << std::endl;
	for (NAMESPACE::map<int, int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << "8 : " << it->first << " ";
	std::cout << std::endl;

	v.erase(v.find(3));
	std::cout << v.size() << " " << v.max_size() << std::endl;
	for (NAMESPACE::map<int, int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << "9 : " << it->first << " ";
	std::cout << std::endl;

	std::cout << v.count(p2.first) << " " << v.max_size() << std::endl;
	for (NAMESPACE::map<int, int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << "10 : " << it->first << " ";
	std::cout << std::endl;

	v.clear();
	std::cout << v.size() << " " << v.max_size() << std::endl;
	for (NAMESPACE::map<int, int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << "11 : " << it->first << " ";
	std::cout << std::endl;

	}

	


	return 0;
}
