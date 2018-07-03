
#include <iostream>


auto maxValue(int f, int s, int t) /* -> int */;


//auto maxValue(int f, int s, int t) {
//	return std::max(f, std::max(s, t));
//}

int main() {
  std::cout << maxValue(1, 2, 3);
}

