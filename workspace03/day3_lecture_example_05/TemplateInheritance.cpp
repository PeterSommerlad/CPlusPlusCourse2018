#include <iostream>
#include <sstream>
#include <string>


template<typename T>
struct parent {
	int foo() const {
		return 42;
	}
	static int const bar{43};
};

int foo() {
	return 1;
}

double const bar{3.14};

template<typename T>
struct gotchas : parent<T> {
	std::string demo() const {
		std::ostringstream result{};
		result << bar << " bar \n";
		result << this->bar << " this->bar \n";
		result << gotchas::bar << " gotchas::bar\n";
		result << foo() << " foo() \n";
		result << this->foo() << " this->foo() \n";
		return result.str();
	}
};

int main() {
	gotchas<int> dg{};
	std::cout << dg.demo();
}
