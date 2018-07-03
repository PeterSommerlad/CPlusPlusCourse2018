#ifndef FIRST_H_
#define FIRST_H_

#include <stdexcept>

template<typename Container>
auto first(Container & container) -> decltype(container[0]) {
	if (container.empty()) {
		throw std::invalid_argument{"Container must not be empty."};
	}
    return container[0];
}



#endif /* FIRST_H_ */
