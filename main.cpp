//вместо map использовать cache map
#include "LRUcache.h"

int main() {
	LRUcashe a(3);


	a.find_and_add1("AAAA");
	a.find_and_add1("FFFF");
	a.find_and_add1("ABAB");
	std::cout << a;
	std::cout << '\n';
	a.find_and_add1("AAAA");
	std::cout << a;
	std::cout << '\n';
	a.find_and_add1("AEAA");
	std::cout << a;
	std::cout << '\n';
	a.find_and_add1("ABAB");
	std::cout << a;

	return 0;
}