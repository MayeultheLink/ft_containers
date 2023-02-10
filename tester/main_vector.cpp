#include "../enable_if.hpp"
#include "../equal.hpp"
#include "../is_integral.hpp"
#include "../iterator_traits.hpp"
#include "../lexicographical_compare.hpp"
#include "../make_pair.hpp"
#include "../pair.hpp"
#include "../random_access_iterator.hpp"
#include "../reverse_iterator.hpp"
#include "../vector.hpp"

#include <iostream>
#include <iterator>
#include <vector>
#include <list>

int main() {

	{
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                            VECTOR                           */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*                                                             */" << std::endl;
	std::cout << "/*-------------------------------------------------------------*/" << std::endl;
	std::cout << std::endl;




	NAMESPACE::vector<int> v;

	std::cout << v.size() << " " << v.max_size() << " " << v.capacity() << std::endl;

	for(int i = 0; i < 10; i++)
		v.push_back(i);

	std::cout << v.size() << " " << v.max_size() << " " << v.capacity() << std::endl;

	for (NAMESPACE::vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	for (NAMESPACE::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	NAMESPACE::vector<int> new_v(v);
	for (NAMESPACE::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (NAMESPACE::vector<int>::iterator it = new_v.begin(); it != new_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	if (new_v == v)
		std::cout << "ok" << std::endl;
	NAMESPACE::vector<int> new_v2;
	new_v2 = v;
	if (new_v2 == v)
		std::cout << "ok" << std::endl;

	v.resize(11);
	std::cout << v.size() << " " << v.max_size() << " " << v.capacity() << std::endl;
	for (NAMESPACE::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	v.resize(5);
	std::cout << v.size() << " " << v.max_size() << " " << v.capacity() << std::endl;
	for (NAMESPACE::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	v.reserve(50);
	std::cout << v.size() << " " << v.max_size() << " " << v.capacity() << std::endl;
	for (NAMESPACE::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << v[2] << std::endl;
	std::cout << v.at(2) << std::endl;
	std::cout << v.front() << std::endl;
	std::cout << v.back() << std::endl;
	std::cout << *v.data() << std::endl;
	std::cout << std::endl;

	v.assign(7, 1);
	std::cout << v.size() << " " << v.max_size() << " " << v.capacity() << std::endl;
	for (NAMESPACE::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	NAMESPACE::vector<int> new_v3;
	for (int i = 26; i < 50; i += 2)
		new_v3.push_back(i);
	v.assign(new_v3.begin(), new_v3.end());
	std::cout << v.size() << " " << v.max_size() << " " << v.capacity() << std::endl;
	for (NAMESPACE::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	v.pop_back();

	std::cout << v.size() << " " << v.max_size() << " " << v.capacity() << std::endl;
	for (NAMESPACE::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	std::cout << v.size() << " " << v.max_size() << " " << v.capacity() << std::endl;
	for (NAMESPACE::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	v.insert(v.begin(), 42);
	std::cout << v.size() << " " << v.max_size() << " " << v.capacity() << std::endl;
	for (NAMESPACE::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	v.insert(v.begin(), 4, 2);
	std::cout << v.size() << " " << v.max_size() << " " << v.capacity() << std::endl;
	for (NAMESPACE::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	NAMESPACE::vector<int> std_tmp;
	for (int i = 0; i < 5; i++)
		std_tmp.push_back(i);
	v.insert(v.begin(), std_tmp.begin(), std_tmp.end());
	std::cout << v.size() << " " << v.max_size() << " " << v.capacity() << std::endl;
	for (NAMESPACE::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	v.erase(v.begin());
	std::cout << v.size() << " " << v.max_size() << " " << v.capacity() << std::endl;
	for (NAMESPACE::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	v.erase(v.begin(), (v.begin() + 2));
	std::cout << v.size() << " " << v.max_size() << " " << v.capacity() << std::endl;
	for (NAMESPACE::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	v.swap(std_tmp);
	std::cout << v.size() << " " << v.max_size() << " " << v.capacity() << std::endl;
	for (NAMESPACE::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	v.clear();
	std::cout << v.size() << " " << v.max_size() << " " << v.capacity() << std::endl;
	for (NAMESPACE::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << typeid(v.get_allocator()).name() << std::endl;

	v.insert(v.begin(), std_tmp.begin(), std_tmp.end());
	std::cout << v.size() << " " << v.max_size() << " " << v.capacity() << std::endl;
	for (NAMESPACE::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;


	}

	


	return 0;
}
