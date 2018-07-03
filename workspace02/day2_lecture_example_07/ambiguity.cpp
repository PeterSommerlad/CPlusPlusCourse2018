#include <iostream>

int factorial(int n) {
  if (n > 1) {
    return n * factorial(n - 1);
  }
  return 1;
}

double factorial(double n) {
  double result = 1;
  if (n < 15) {
    return factorial(static_cast<int>(n));
  }
  while (n > 1) {
    result *= n;
    --n;
  }
  return result;
}

int main() {
  std::cout << factorial(3) << '\n';
  std::cout << factorial(1e2) << '\n';

  std::cout << factorial(10u) << '\n';
  std::cout << factorial(1e1L) << '\n';
}
