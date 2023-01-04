#include <iostream>
#include <map>
#include <vector>

int main ()
{
	std::cout << typeid(std::map<int, int>::iterator::iterator_category).name() << std::endl;
	std::cout << typeid(std::iterator_traits<std::vector<int>::iterator>::iterator_category).name() << std::endl;
	std::cout << typeid(std::iterator_traits<std::vector<int>::iterator*>::iterator_category).name() << std::endl;
	std::cout << typeid(std::iterator_traits<int*>::iterator_category).name() << std::endl;

	std::vector<int>	vect;

	vect.push_back(3);
	vect.push_back(2);
	vect.push_back(1);
	std::reverse_iterator<std::vector<int>::iterator> rit(vect.begin());
	std::cout << vect[-2] << std::endl;
	std::cout << *rit << std::endl;

	return 0;
}
