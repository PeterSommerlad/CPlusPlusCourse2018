#include <chrono>
#include <string>
#include <iostream>

void callByValue(std::string parameter) {
}

void callByReference(std::string const & parameter) {

}


template <typename Function, typename Argument>
auto measure(Function const & functionToMeasure, Argument const & arg, unsigned repetitions) {
	using Time = std::chrono::high_resolution_clock;
	auto startTime = Time::now();
	for (auto i = 0u; i < repetitions; ++i) {
		functionToMeasure(arg);
	}
	auto endTime = Time::now();
	return endTime - startTime;
}

int main() {
	using Duration = std::chrono::milliseconds;

	std::string const largeString(10000000, '*');
	unsigned const repetitions = 100u;

	auto callByValueDuration = measure(callByValue, largeString, repetitions);
	std::cout << "Average call by value duration: " << std::chrono::duration_cast<Duration>(callByValueDuration).count() /repetitions << "ms\n";

	auto callByReferenceDuration = measure(callByReference, largeString, repetitions);
	std::cout << "Average call by reference duration: " << std::chrono::duration_cast<Duration>(callByReferenceDuration).count() / repetitions << "ms\n";
}
