#include "templatewithstaticmember.h"
#include <iostream>

int main() {
	int setDummyTo42();  //declare setDummyTo42()
	std::cout << staticmember<double>::dummy << '\n';
	std::cout << staticmember<int>::dummy << '\n';
	std::cout << setDummyTo42() << '\n';
	std::cout << staticmember<int>::dummy << '\n';
}
