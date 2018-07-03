#include "sack.h"

#include <iostream>

int main() {
	Sack<int> sack{};
	sack.putInto(1);
	sack.putInto(2);
	sack.putInto(3);
	sack.putInto(4);
	sack.putInto(5);
	std::cout << sack.getOut();
}
