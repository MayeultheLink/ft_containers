#include "map.hpp"

#include <iostream>
#include <map>

template <typename T, typename U>
void print(NAMESPACE::map<T, U> v) {
	std::cout << v.size() << std::endl;
	for (typename NAMESPACE::map<T, U>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << it->first << it->second;
}

int main() {

/*------------------ CONSTRUCTORS/DESTRUCTOR -------------------*/

		NAMESPACE::map<int, int> v1;
		print(v1);
		for (int i = 0; i < 50; i++)
			v1[i] = i;

		NAMESPACE::map<int, int> v2(v1.begin(), v1.end());
		print(v2);

		NAMESPACE::map<int, int> v3(v2);
		print(v3);

		NAMESPACE::map<int, int> v4;
		v4 = v3;
		print(v4);

		if (v1.value_comp()(*v3.begin(), *v4.begin()))
			std::cout << "ok";
		else
			std::cout << "error";

/*------------------ ELEMENT ACCESS -------------------*/

		std::cout << v1.at(2);
		std::cout << v1[3];

		std::cout << v2.at(3);
		std::cout << v2[2];

/*------------------ ITERATORS -------------------*/

		for (NAMESPACE::map<int, int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			std::cout << it->first;
			it->second = 5;
		}
		std::cout << (++(++(++(v1.begin()))))->first << (--(--(--(v1.end()))))->first;

		for (NAMESPACE::map<int, int>::const_iterator it = v1.begin(); it != v1.end(); it++)
			std::cout << it->first;

		NAMESPACE::map<int, int>::iterator it = v1.begin();
		v1.erase(it);
		if (it != v1.end())
			std::cout << it->first;

/*------------------ REVERSE ITERATORS -------------------*/

		for (NAMESPACE::map<int, int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++)
		{
			std::cout << it->first;
			it->second = 5;
		}
		std::cout << (++(++(++(v1.rbegin()))))->first << (--(--(--(v1.rend()))))->first;

		for (NAMESPACE::map<int, int>::const_reverse_iterator it = v1.rbegin(); it != v1.rend(); it++)
			std::cout << it->first;

/*------------------ CAPACITY -------------------*/

		std::cout << v1.empty();
		print(v1);

/*------------------ MODIFIERS -------------------*/

		v1.clear();
		print(v1);

		NAMESPACE::map<int, int>::iterator it9 = v2.insert(NAMESPACE::make_pair(51, 51)).first;
		std::cout << it9->first;

		v2.insert(v3.begin(), v3.end());
		print(v2);

		v2.erase(v2.begin());
		print(v2);
		for (; it9 != v2.begin(); it9--)
			std::cout << it9->first;

		v3.erase(++(++(++(v3.begin()))), --(--(--(v3.end()))));
		print(v3);

		NAMESPACE::map<int, int>::iterator its = v3.begin();
		std::cout << its->first;
		v3.swap(v2);
		print(v3);
		print(v2);
		std::cout << its->first;
		std::cout << (*++its).first;
		print(v3);
		print(v2);
		v3.swap(v2);
		print(v3);
		print(v2);

/*------------------ LOOK UP -------------------*/

		std::cout << v1.count(3);
		
		NAMESPACE::map<int, int>::iterator it3 = v1.find(3);
		if (it3 != v1.end())
			std::cout << it3->first;
		NAMESPACE::map<int, int>::const_iterator it4 = v1.find(3);
		if (it4 != v1.end())
			std::cout << it4->first;

		NAMESPACE::map<int, int>::iterator it5 = v1.equal_range(6).first;
		NAMESPACE::map<int, int>::iterator it6 = v1.equal_range(6).second;
		if (it5 != v1.end())
			std::cout << it5->first;
		if (it6 != v1.end())
			std::cout << it6->first;

		NAMESPACE::map<int, int>::iterator it7 = v1.lower_bound(9);
		if (it7 != v1.end())
			std::cout << it7->first;
		NAMESPACE::map<int, int>::iterator it8 = v1.upper_bound(9);
		if (it8 != v1.end())
			std::cout << it8->first;

/*------------------ NON MEMBER FUNCTIONS -------------------*/

		if (v1 == v2)
			std::cout << "ok";
		else
			std::cout << "error";
		if (v1 != v2)
			std::cout << "ok";
		else
			std::cout << "error";

		v2.insert(v2.begin(), NAMESPACE::make_pair(1, 1));
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

	return 0;
}
