#include <chrono>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>


void callByValue(std::string parameter) {
}

void callByReference(std::string const & parameter) {

}


template <typename Duration, typename Function, typename...Arguments>
auto measure(Function const & functionToMeasure, Arguments &&...args) {
	using Time = std::chrono::high_resolution_clock;
	auto startTime = Time::now();
	std::invoke(functionToMeasure, std::forward<Arguments>(args)...);
	auto endTime = Time::now();
	return std::chrono::duration_cast<Duration>(endTime - startTime);
}

int main() {
	using Duration = std::chrono::milliseconds;

	std::string const largeString(100000000, '*');
	unsigned const repetitions = 100u;
	std::vector largeStrings(repetitions, largeString);
	Duration callByValueDuration{};
	Duration callByReferenceDuration{};
	Duration callByValueWithMoveDuration{};
	for (auto i = 0u; i < repetitions; ++i) {
		callByValueDuration += measure<Duration>(callByValue, largeStrings[i]);
		callByReferenceDuration += measure<Duration>(callByReference, largeStrings[i]);
		callByValueWithMoveDuration += measure<Duration>(callByValue, std::move(largeStrings[i]));
	}
	std::cout << "Call by value duration: " << std::chrono::duration_cast<Duration>(callByValueDuration).count() / repetitions << "ms\n";
	std::cout << "Call by reference duration: " << std::chrono::duration_cast<Duration>(callByReferenceDuration).count() / repetitions << "ms\n";
	std::cout << "Call by value with move duration: " << std::chrono::duration_cast<Duration>(callByValueWithMoveDuration).count() / repetitions << "ms\n";
}
