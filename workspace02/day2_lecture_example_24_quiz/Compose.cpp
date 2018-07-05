#include <iostream>
#include <functional>


template <typename Ret, typename F, typename G, typename Arg>
Ret compose(F const & f, G const & g, Arg arg) {
  return f(g(arg));
}


int main() {
	std::cout << compose<int>(std::negate{}, [](auto v) {return v * v;}, 9);
}
