#include <iostream>


template<typename Head, typename...Tail>
void println(std::ostream & out, Head const & head, Tail const &...tail) {
	out << head;
	if constexpr(sizeof...(tail)) {
		out << ", ";
		println(out, tail...);
	} else {
		out << '\n';
	}
}


int main() {
	auto & out = std::cout;
	println(out, 1, 2, 3, "hello", ' ', "World");
}
