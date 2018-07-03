#include <iostream>

void square(int x, void print(int)) {
  print(x * x);
}

int main() {
  auto p = [](auto value) {std::cout << value;};
  square(5, p);
}
