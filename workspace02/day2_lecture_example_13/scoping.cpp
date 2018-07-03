#include <iostream>

void showScopingRules(int i, double d, std::ostream & out) {
	// cannot use name i instead of j
	unsigned j { 1 };
	out << i << "\n";
	{
		char i { 'd' }; // shadows parameter i
		// parameter i not accessible but d is
		out << i << " " << d << "\n";
	}
	++i; // that is the parameter i
		 // no longer shadowed
	for (auto i = 0u; i < j; ++i) {
		// another i
		out << i << "\n";
	}
	// parameter i again
	out << i << "\n";
}

int main() {
	showScopingRules(42, 2.75, std::cout);
}
