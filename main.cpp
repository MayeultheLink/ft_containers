#include <iostream>
#include <vector>
#include "is_integral.hpp"
#include "pair.hpp"
#include "make_pair.hpp"
#include "lexicographical_compare.hpp"
#include "equal.hpp"

class A {};

int main()
{
	/*
	std::cout << "ft  : " << ft::is_integral<short>::value << std::endl;
	std::cout << "std : " << std::is_integral<short>::value << std::endl;

	std::cout << std::endl;

	ft::pair<int, char> ftpair(1, 'c');
	std::pair<int, char> stdpair(1, 'c');
	std::cout << "ft  : " << ftpair.first << " " << ftpair.second << std::endl;
	std::cout << "std : " << stdpair.first << " " << stdpair.second << std::endl;
	ft::pair<int, char> newftpair(2, 'd');
	std::cout << "ft  : " << (ftpair == newftpair) << std::endl;
	std::cout << "ft  : " << (ftpair <= newftpair) << std::endl;
	ftpair = newftpair;
	std::cout << "ft  : " << (ftpair == newftpair) << std::endl;
	std::cout << "ft  : " << ftpair.first << " " << ftpair.second << std::endl;

	ft::pair<int, char> ftpair(1, 'c');
	ft::pair<int, char> newftpair(ftpair);
	ft::pair<int, char> *p = new ft::pair<int, char>();
	std::cout << "ft  : " << p->first << " " << newftpair.second << std::endl;
	delete p;

	    char n = 'c';
    int a[5] = {1, 2, 3, 4, 5};

    // build a pair from two ints
    auto p1 = ft::make_pair(n, a[1]);
    std::cout << "The value of p1 is "
              << "(" << p1.first << ", " << p1.second << ")\n";
*/
	std::vector<int> v1 = {1, 2, 3};
	std::vector<int> v2 = {1, 2, 4};
	std::cout << ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;

	return 0;
}
