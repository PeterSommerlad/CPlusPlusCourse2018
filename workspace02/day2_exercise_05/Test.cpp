#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "read.h"

#include <sstream>
#include <string>
#include <tuple>

void testSampleInput() {
	using namespace std::string_literals;
	std::istringstream input{"1 2 3 hello b World"};

	int one;
	int two;
	int three;
	std::string hello;
	char b;
	std::string world;
	read(input, one, two, three, hello, b, world);

	ASSERT_EQUAL(std::tuple(1, 2, 3, "hello"s, 'b', "World"s),
			     std::tie(one, two, three, hello, b, world));
}

void testReadWithSingleArgument() {
	std::istringstream input{"42"};
	unsigned value;
	read(input, value);
	ASSERT_EQUAL(42, value);
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(testSampleInput));
	s.push_back(CUTE(testReadWithSingleArgument));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
