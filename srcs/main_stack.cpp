#include "stack.hpp"

#include <iostream>
#include <stack>
#include <list>

template <typename T>
void print(NAMESPACE::stack<T> v) {
	std::cout << v.size() << v.empty() << std::endl;
}

int main() {

		NAMESPACE::stack<int> v1;
		print(v1);

		v1.push(5);

		NAMESPACE::stack<int> v2(v1);
		print(v2);

		NAMESPACE::stack<int> v3;
		v3 = v2;
		print(v3);

		std::cout << v3.top();
		std::cout << v1.empty();
		std::cout << v2.size();

		for (int i = 0; i < 1000; i++)
			v1.push(i);
		print(v1);
		v1.pop();
		v1.pop();
		v1.pop();
		v1.pop();
		v1.pop();
		v1.pop();
		v1.pop();
		v1.pop();
		print(v1);

		if (v1 == v2)
			std::cout << "ok";
		else
			std::cout << "error";
		if (v1 != v2)
			std::cout << "ok";
		else
			std::cout << "error";

		v2.push(1);
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

	return 0;
}
