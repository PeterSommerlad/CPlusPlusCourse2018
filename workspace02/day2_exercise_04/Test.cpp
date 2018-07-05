#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "min.h"


void testMinOfSingleArgument() {
	ASSERT_EQUAL(5, min(5));
}

void testMinOfManyArguments() {
	ASSERT_EQUAL(1, min(17, 5, 1, 6, 9));
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(testMinOfSingleArgument));
	s.push_back(CUTE(testMinOfManyArguments));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
