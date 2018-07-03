#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "divide.h"

#include <stdexcept>

void testDivisorZero() {
	ASSERT_THROWS(divide(10, 0), std::invalid_argument);
}

void testDivisionBy5(){
	ASSERT_EQUAL(30, divide(150, 5));
}



bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(testDivisorZero));
	s.push_back(CUTE(testDivisionBy5));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
