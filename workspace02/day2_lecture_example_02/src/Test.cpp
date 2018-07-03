#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "maxValue.h"
#include <vector>

void testMaxValue() {
	std::vector values{1, 3, 2};
	ASSERT_EQUAL(3, maxValue(values));
}

void testMaxValueThrowsIfEmpty() {
	std::vector<int> values{};
	ASSERT_THROWS(maxValue(values), std::invalid_argument);
}

void testMaxValueAuto() {
	std::vector values{1, 3, 2};
	ASSERT_EQUAL(3, maxValueAuto(values));
}

void testMaxValueAutoThrowsIfEmpty() {
	std::vector<int> values{};
	ASSERT_THROWS(maxValueAuto(values), std::invalid_argument);
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(testMaxValue));
	s.push_back(CUTE(testMaxValueThrowsIfEmpty));
	s.push_back(CUTE(testMaxValueAuto));
	s.push_back(CUTE(testMaxValueAutoThrowsIfEmpty));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
