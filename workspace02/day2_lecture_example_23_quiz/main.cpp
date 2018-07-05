#include <iostream>

template<typename T>
inline T divideRoundUp(T lhs, T rhs) {
  return (lhs + rhs - 1) / rhs;
}

int main() {
	std::cout << divideRoundUp(5,  2);
}
