#include <chrono>
#include <string>
#include <iostream>
#include <functional>

void callByValue(std::string parameter) {
}

void callByReference(std::string const & parameter) {

}


void arbitraryFunction(int, double, std::string) {

}

template <typename Function, typename...Arguments>
auto measure(Function const & functionToMeasure, unsigned repetitions, Arguments const &...args) {
	using Time = std::chrono::high_resolution_clock;
	auto startTime = Time::now();
	for (auto i = 0u; i < repetitions; ++i) {
		functionToMeasure(args...);
	}
	auto endTime = Time::now();
	return endTime - startTime;
}

template <typename...Args>
auto createContainer(Args const &...args) {
	return std::vector{args...};
}

int main() {
	using Duration = std::chrono::milliseconds;

	std::string const largeString(10000000, '*');
	unsigned const repetitions = 100u;

	auto callByValueDuration = measure(callByValue, repetitions, largeString);
	std::cout << "Average call by value duration: " << std::chrono::duration_cast<Duration>(callByValueDuration).count() /repetitions << "ms\n";

	auto callByReferenceDuration = measure(callByReference, repetitions, largeString);
	std::cout << "Average call by reference duration: " << std::chrono::duration_cast<Duration>(callByReferenceDuration).count() / repetitions << "ms\n";

	measure(arbitraryFunction, 100, 1, 1.5, "adsf");


	createContainer(1, 2, 3.4, 4);
}
