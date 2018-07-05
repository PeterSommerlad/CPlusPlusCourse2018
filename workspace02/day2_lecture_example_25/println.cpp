#include <iostream>

void println(std::ostream & out) {
	out << '\n';
}

template<typename Head, typename...Tail>
void println(std::ostream & out, Head const & head, Tail const &...tail) {
	out << head;
	if (sizeof...(tail)) {
		out << ", ";
	}
	println(out, tail...);
}


int main() {
	auto & out = std::cout;
	println(out, 1, 2, 3, "hello", ' ', "World");
}
