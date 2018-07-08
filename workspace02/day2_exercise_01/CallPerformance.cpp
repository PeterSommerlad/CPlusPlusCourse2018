#include <chrono>
#include <string>
#include <iostream>

void callByValue(std::string const parameter) {
}

void callByReference(std::string const & parameter) {

}

int main() {
	using Clock = std::chrono::high_resolution_clock;
	using Duration = std::chrono::microseconds;

	std::string const largeString(1000, '*');
	unsigned const repetitions = 1000000u;
	
	auto callByValueStartTime = Clock::now();
	for (auto i = 0u; i < repetitions; ++i) {
		callByValue(largeString);
	}
	auto callByValueEndTime = Clock::now();
	auto callByValueDuration = callByValueEndTime - callByValueStartTime;
	std::cout << "Average call by value duration: " << std::chrono::duration_cast<Duration>(callByValueDuration).count()  << "ms\n";
	
	auto callByReferenceStartTime = Clock::now();
	for (auto i = 0u; i < repetitions; ++i) {
		callByReference(largeString);
	}
	auto callByReferenceEndTime = Clock::now();
	auto callByReferenceDuration = callByReferenceEndTime - callByReferenceStartTime;
	std::cout << "Average call by reference duration: " << std::chrono::duration_cast<Duration>(callByReferenceDuration).count()  << "ms\n";
}

