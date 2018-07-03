#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "sack.h"

#include <vector>

void createSackFromIterators() {
	std::vector values{3, 1, 4, 1, 5, 9, 2, 6};
	Sack<int> aSack{begin(values), end(values)};
	ASSERT_EQUAL(values.size(), aSack.size());
}

void defaultConstructorStillWorks() {
	Sack<char> defaultCtor{};
	ASSERT_EQUAL(0, defaultCtor.size());
}

void creationAlsoAllowsTwoIntsBraces() {
	Sack<unsigned> aSack{10, 3};
	ASSERT_EQUAL(2, aSack.size());
	ASSERT_EQUAL(3, aSack.getOut());
}

void creationAlsoAllowsTwoIntsParens() {
	Sack<unsigned> aSack(10, 3);
	ASSERT_EQUAL(10, aSack.size());
	ASSERT_EQUAL(3, aSack.getOut());
}

void createSackFromInitializerList() {
	Sack<char> charSack{'a', 'b', 'c'};
	ASSERT_EQUAL(3, charSack.size());
}

void testConvertSackToVector() {
	Sack<unsigned> aSack{1, 2, 3};
	auto values = static_cast<std::vector<unsigned>>(aSack);
	ASSERT_EQUAL((std::vector{1u, 2u, 3u}), values);
}

void testImplicitDeductionGuide() {
	Sack charSack{'a', 'b', 'c'};
	ASSERT_EQUAL(3, charSack.size());
}

//void testSurprisingDeduction() {
//  std::vector values{3, 1, 4, 1, 5, 9, 2, 6};
//  Sack aSack{begin(values), end(values)};
//  ASSERT_EQUAL(values.size(), aSack.size());
//}

void testDeductionForIterators() {
	std::vector values{3, 1, 4, 1, 5, 9, 2, 6};
	Sack aSack(begin(values), end(values));
	ASSERT_EQUAL(values.size(), aSack.size());
}

void testDeductionAndMultiDefaultConstruction() {
	Sack aSack(10, 3u);
	ASSERT_EQUAL(10, aSack.size());
	ASSERT_EQUAL(3, aSack.getOut());
}


void testSetAsSackContainer() {
	Sack<unsigned, std::set> aSack{1, 2, 3};
	ASSERT_EQUAL(3, aSack.size());
	ASSERT_EQUAL(2, aSack.getOut());
}

void testMakeSack() {
	auto setSack = makeSack<std::set>({'a', 'b', 'c', 'c'});
	ASSERT_EQUAL(3, setSack.size());
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(createSackFromIterators));
	s.push_back(CUTE(defaultConstructorStillWorks));
	s.push_back(CUTE(creationAlsoAllowsTwoIntsBraces));
	s.push_back(CUTE(creationAlsoAllowsTwoIntsParens));
	s.push_back(CUTE(createSackFromInitializerList));
	s.push_back(CUTE(testConvertSackToVector));
	s.push_back(CUTE(testImplicitDeductionGuide));
	s.push_back(CUTE(testDeductionForIterators));
	s.push_back(CUTE(testDeductionAndMultiDefaultConstruction));
	s.push_back(CUTE(testSetAsSackContainer));
	s.push_back(CUTE(testMakeSack));
//	s.push_back(CUTE(testSurprisingDeduction));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
	return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
