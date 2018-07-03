#include "divide.h"

#include <stdexcept>

int divide(int dividend, int divisor) {
	if (divisor == 0) {
		throw std::invalid_argument{"Divisor must not be 0."};
	}
	return dividend / divisor;
}
