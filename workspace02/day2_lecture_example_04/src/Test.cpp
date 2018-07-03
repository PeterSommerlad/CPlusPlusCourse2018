#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "first.h"

#include <vector>

void testFirstReturnsFirst() {
	std::vector const values{4, 5, 6};
	ASSERT_EQUAL(4, first(values));
}

void testFirstReturnsFirstByLvalueReference(){
	std::vector expected{5, 5, 6};
	std::vector values{4, 5, 6};
	++first(values);
	ASSERT_EQUAL(expected, values);
}



bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(testFirstReturnsFirst));
	s.push_back(CUTE(testFirstReturnsFirstByLvalueReference));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
