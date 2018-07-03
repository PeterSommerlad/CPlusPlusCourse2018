#include <iostream>



template<typename T>
T max(T a, T b) {
  return (a < b) ? b : a;
}


int main() {
	std::cout << "max(Peter, Toni) = " << max("Peter", "Toni") << '\n';
	std::cout << "max<std::string>(Peter, Toni) = " << max<std::string>("Peter", "Toni") << '\n';
}
