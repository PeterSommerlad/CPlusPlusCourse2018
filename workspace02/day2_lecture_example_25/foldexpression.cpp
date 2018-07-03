#include <iostream>


template<typename...T>
int sum(T...pack) {
  return (pack + ...);
}

int main() {
  std::cout << sum(1, 2, 3, 4, 5);
}
