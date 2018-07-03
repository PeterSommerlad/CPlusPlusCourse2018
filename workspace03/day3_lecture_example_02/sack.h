#ifndef SACK_H_
#define SACK_H_

#include <stdexcept>
#include <vector>


template<typename T>
class Sack {
	using SackType = std::vector<T>;
	using size_type = typename SackType::size_type;
	SackType theSack{};
public:
	bool empty() const {
		return theSack.empty();
	}
	size_type size() const {
		return theSack.size();
	}
	void putInto(T const & item) {
		theSack.push_back(item);
	}
	T getOut();
};

template<typename T>
inline T Sack<T>::getOut() {
	if (empty()) {
		throw std::logic_error{"Empty Sack"};
	}
	auto index = static_cast<size_type>(rand() % size());
	T retval{theSack.at(index)};
	theSack.erase(theSack.begin() + index);
	return retval;
}


#endif /* SACK_H_ */
