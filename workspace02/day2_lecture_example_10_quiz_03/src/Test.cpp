#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "intsUpTo.h"

#include <vector>

void testIntsUpToZero() {
	std::vector const expected{0};
	auto const result = intsUpTo(0);
	ASSERT_EQUAL(expected, result);
}

void testIntsUpToWithRange(){
	std::vector const expected{3, 4, 5};
	auto const result = intsUpTo(3, 5);
	ASSERT_EQUAL(expected, result);
}

void testIntsUpToThrowsForReverseRange(){
	ASSERT_THROWS(intsUpTo(5, 3), std::invalid_argument);
}


bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(testIntsUpToZero));
	s.push_back(CUTE(testIntsUpToWithRange));
	s.push_back(CUTE(testIntsUpToThrowsForReverseRange));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
