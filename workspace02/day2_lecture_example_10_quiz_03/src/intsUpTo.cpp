#include "intsUpTo.h"
#include <cstddef>
#include <iterator>
#include <numeric>
#include <stdexcept>
#include <vector>

std::vector<int> intsUpTo(std::size_t to) {
	return intsUpTo(0, to);
}

std::vector<int> intsUpTo(std::size_t from, std::size_t to) {
	if (from > to) {
		throw std::invalid_argument { "'from' must be less or equal to 'to'" };
	}
	std::vector<int> values(to - from + 1);
	iota(begin(values), end(values), from);
	return values;
}

