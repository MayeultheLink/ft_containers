#include "../headers/vector.hpp"

#include <iostream>
#include <vector>
#include <list>

template <typename T>
void print(NAMESPACE::vector<T> v) {
	std::cout << v.size() << " " << v.max_size() << " " << v.capacity() << std::endl;
}

int main() {

/*------------------ CONSTRUCTORS/DESTRUCTOR -------------------*/

	{
		NAMESPACE::vector<int> v1;
		print(v1);

		NAMESPACE::vector<int> v2(1000, 0);
		print(v2);

		std::list<int> lst;
		lst.assign(1000, 1);
		NAMESPACE::vector<int> v3(lst.begin(), lst.end());
		print(v3);
		NAMESPACE::vector<int> v4(v3);
		print(v4);
		NAMESPACE::vector<int> v5 = v4;
		print(v5);
	}

/*------------------ ASSIGN -------------------*/

	{
		NAMESPACE::vector<int> v;
		v.assign(1000, 0);
		print(v);
		std::list<int> lst;
		lst.assign(1000, 1);
		v.assign(lst.begin(), lst.end());
		print(v);
	}

/*------------------ ELEMENT ACCESS -------------------*/

	{
		NAMESPACE::vector<int> v1(1000, 0);
		std::cout << v1.at(5);
		std::cout << v1[5];
		std::cout << v1.front();
		std::cout << v1.back();
		//std::cout << v1.data();

		const NAMESPACE::vector<int> v2(1000, 1);
		std::cout << v2.at(5);
		std::cout << v2[5];
		std::cout << v2.front();
		std::cout << v2.back();
		//std::cout << v2.data();

	}

/*------------------ ITERATORS -------------------*/

	{
		NAMESPACE::vector<int> v1(1000, 0);
		for (NAMESPACE::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			std::cout << *it;
			*it = 5;
		}
		std::cout << *(++(++(++(v1.begin())))) << *(--(--(--(v1.end()))));

		for (NAMESPACE::vector<int>::const_iterator it = v1.begin(); it != v1.end(); it++)
			std::cout << *it;

		NAMESPACE::vector<int>::iterator it = v1.begin();
		NAMESPACE::vector<int>::const_iterator itc = ++v1.begin();
		if (it == itc)
			std::cout << "error";
		
	}

/*------------------ REVERSE ITERATORS -------------------*/

	{
		NAMESPACE::vector<int> v1(1000, 0);
		for (NAMESPACE::vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++)
		{
			std::cout << *it;
			*it = 5;
		}
		std::cout << *(++(++(++(v1.rbegin())))) << *(--(--(--(v1.rend()))));

		for (NAMESPACE::vector<int>::const_reverse_iterator it = v1.rbegin(); it != v1.rend(); it++)
			std::cout << *it;

		NAMESPACE::vector<int>::reverse_iterator it = v1.rbegin();
		NAMESPACE::vector<int>::const_reverse_iterator itc = ++v1.rbegin();
		if (it == itc)
			std::cout << "error";
		
	}

/*------------------ CAPACITY -------------------*/

	{

		NAMESPACE::vector<int> v1;
		std::cout << v1.empty();
		NAMESPACE::vector<int> v2(1000, 0);
		std::cout << v2.empty();
		print(v1);
		print(v2);

		v1.reserve(1);
		v2.reserve(1);
		print(v1);
		print(v2);

	}

/*------------------ MODIFIERS -------------------*/

	{
		NAMESPACE::vector<int> v1;
		v1.clear();
		print(v1);

		v1.assign(17, 0);
		print(v1);
		v1.clear();
		print(v1);

		v1.reserve(25);
		print(v1);
		v1.clear();
		print(v1);

		NAMESPACE::vector<int> v2;
		NAMESPACE::vector<int>::iterator it = v2.insert(v2.begin(), 5);
		std::cout << *it;
	      	v2.insert(++v2.begin(), 5, 0);
		print(v2);

		NAMESPACE::vector<int> v3(1000, 0);
		v2.insert(--(--(v2.end())), v3.begin(), v3.end());
		print(v2);

		v2.erase(v2.begin());
		print(v2);
		v3.erase(++(++(++(v3.begin()))), --(--(--(v3.end()))));
		print(v3);

		v2.push_back(8);
		print(v2);
		v2.pop_back();
		print(v2);
		v2.pop_back();
		v2.pop_back();
		v2.pop_back();
		v2.pop_back();
		v2.pop_back();
		v2.pop_back();
		v2.pop_back();
		v2.pop_back();
		v2.pop_back();
		v2.pop_back();
		v2.pop_back();
		v2.pop_back();
		print(v2);

		v3.resize(43);
		print(v3);
		v3.resize(4300);
		print(v3);

		NAMESPACE::vector<int>::iterator its = v3.begin();
		std::cout << *its;
		v3.swap(v2);
		print(v3);
		print(v2);
		std::cout << *its;
		std::cout << *++its;
		v3.resize(43);
		print(v3);
		print(v2);
		v3.swap(v2);
		print(v3);
		print(v2);

	}

/*------------------ NON MEMBER FUNCTIONS -------------------*/

	{

		NAMESPACE::vector<int> v1(1000, 0);
		NAMESPACE::vector<int> v2(1000, 0);
		if (v1 == v2)
			std::cout << "ok";
		else
			std::cout << "error";
		if (v1 != v2)
			std::cout << "ok";
		else
			std::cout << "error";

		v2.insert(v2.begin(), 1);
		if (v1 != v2)
			std::cout << "ok";
		else
			std::cout << "error";
		if (v1 < v2)
			std::cout << "ok";
		else
			std::cout << "error";
		if (v1 <= v2)
			std::cout << "ok";
		else
			std::cout << "error";
		if (v1 >= v2)
			std::cout << "ok";
		else
			std::cout << "error";
		if (v1 > v2)
			std::cout << "ok";
		else
			std::cout << "error";

		NAMESPACE::swap(v1, v2);
		print(v1);
		print(v2);

	}
	
	return 0;
}
