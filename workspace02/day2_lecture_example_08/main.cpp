
#include "increment.h"

#include <iostream>

int main() {
	int counter{0};
	incr(counter);    //uses default for delta
	incr(counter, 5);
	std::cout << counter;
}


