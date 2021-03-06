#include <chrono>
#include <string>
#include <iostream>
#include <utility>
#include <vector>


std::string callByValue(std::string parameter) {
	return parameter;
}

void callByReference(std::string const & parameter) {

}

int main() {
	using Time = std::chrono::high_resolution_clock;
	using Duration = std::chrono::milliseconds;

	std::string const largeString(10000000, '*');
	unsigned const repetitions = 1000u;
	std::vector largeStrings(repetitions, largeString);
	
	auto callByValueStartTime = Time::now();
	for (auto i = 0u; i < repetitions; ++i) {
		callByValue(largeStrings[i]);
	}
	auto callByValueEndTime = Time::now();
	auto callByValueDuration = callByValueEndTime - callByValueStartTime;
	std::cout << "Average call by value duration: " << std::chrono::duration_cast<Duration>(callByValueDuration).count()  << "ms\n";
	
	auto callByReferenceStartTime = Time::now();
	for (auto i = 0u; i < repetitions; ++i) {
		callByReference(largeStrings[i]);
	}
	auto callByReferenceEndTime = Time::now();
	auto callByReferenceDuration = callByReferenceEndTime - callByReferenceStartTime;
	std::cout << "Average call by reference duration: " << std::chrono::duration_cast<Duration>(callByReferenceDuration).count()  << "ms\n";


	auto callByValueWithMoveStartTime = Time::now();
	for (auto i = 0u; i < repetitions; ++i) {
		largeStrings[i] = callByValue(std::move(largeStrings[i]));
	}
	auto callByValueWithMoveEndTime = Time::now();
	auto callByValueWithMoveDuration = callByValueWithMoveEndTime - callByValueWithMoveStartTime;
	std::cout << "Average call by value with move duration: " << std::chrono::duration_cast<Duration>(callByValueWithMoveDuration).count()  << "ms\n";
}

