#ifndef MAXPOSITION_H_
#define MAXPOSITION_H_

#include <stdexcept>

template<typename Container>
typename Container::value_type maxValue(Container const & container) {
	if (container.empty()) {
		throw std::invalid_argument{"Container must not be empty."};
	}
	return *max_element(begin(container), end(container));
}

template<typename Container>
auto maxValueAuto(Container const & container) {
	if (container.empty()) {
		throw std::invalid_argument{"Container must not be empty."};
	}
	return *max_element(begin(container), end(container));
}


#endif /* MAXPOSITION_H_ */
