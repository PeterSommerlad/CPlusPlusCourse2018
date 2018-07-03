
#include <iostream>
#include <functional>

void applyAndPrint(double x, double fp(double)) {
  std::cout << "fp(" << x << ") = " << fp(x) << '\n';
}

void applyAndPrint(double x, std::function<double(double)> f) {
  std::cout << "f(" << x << ") = " << f(x) << '\n';
}

double square(double value) {
	return value * value;
}

int main() {
	double const value{1.5};
	applyAndPrint(value, square);
	double divisor = 2;
	applyAndPrint(value, [divisor](auto value) {return value / divisor;});
}
