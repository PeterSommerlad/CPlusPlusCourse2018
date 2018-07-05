#include <iostream>

//template <typename...T>
//T max(T const & head, T const &...args) {
//  T maxOfRest = max(args...);
//  return head > maxOfRest ? head : maxOfRest;
//}



template <typename Head, typename...T>
auto max(Head const & head, T const &...args) {
  if constexpr(sizeof...(args)) {
	  auto const & maxOfRest = max(args...);
	  return head > maxOfRest ? head : maxOfRest;
  }
  return head;
}


int main() {
	std::cout << max(1, 4, 5, 3, 2);
}


