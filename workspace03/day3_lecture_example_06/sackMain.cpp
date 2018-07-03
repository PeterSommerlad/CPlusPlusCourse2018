#include "sack.h"

#include <iostream>

int main() {
	Sack<char const *> words{};
	words.putInto("Car");
	words.putInto("House");
	words.putInto("Tree");
	std::cout << words.getOut() << '\n';
	std::cout << words.getOut() << '\n';
	std::cout << words.getOut() << '\n';

//	Sack<int *> wontCompile{};
}
