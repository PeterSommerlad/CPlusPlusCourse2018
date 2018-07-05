#include <chrono>
#include <string>
#include <iostream>

void callByValue(std::string parameter) {
}

void callByReference(std::string const & parameter) {

}

int main() {
	using Time = std::chrono::high_resolution_clock;
	using Duration = std::chrono::milliseconds;

	std::string const largeString(10000000, '*');
	unsigned const repetitions = 100u;
	
	auto callByValueStartTime = Time::now();
	for (auto i = 0u; i < repetitions; ++i) {
		callByValue(largeString);
	}
	auto callByValueEndTime = Time::now();
	auto callByValueDuration = callByValueEndTime - callByValueStartTime;
	std::cout << "Average call by value duration: " << std::chrono::duration_cast<Duration>(callByValueDuration).count() /repetitions << "ms\n";
	
	auto callByReferenceStartTime = Time::now();
	for (auto i = 0u; i < repetitions; ++i) {
		callByReference(largeString);
	}
	auto callByReferenceEndTime = Time::now();
	auto callByReferenceDuration = callByReferenceEndTime - callByReferenceStartTime;
	std::cout << "Average call by reference duration: " << std::chrono::duration_cast<Duration>(callByReferenceDuration).count() / repetitions << "ms\n";
}

