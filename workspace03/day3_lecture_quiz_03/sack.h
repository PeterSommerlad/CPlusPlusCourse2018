#ifndef SACK_H_
#define SACK_H_

#include <stdexcept>
#include <string>
#include <vector>

template<typename T>
class Sack {
	using SackType = std::vector<T>;
	using size_type = typename SackType::size_type;
	SackType theSack{};
public:
	template <typename Iter>
	Sack(Iter begin, Iter end)
			: theSack(begin, end) {
	}

	Sack(std::initializer_list<T> values)
			: theSack(values) {
	}


	Sack(size_type n, T const & value)
			: theSack(n, value) {
	}
	bool empty() const {
		return theSack.empty();
	}
	size_type size() const {
		return theSack.size();
	}
	void putInto(T const & item) {
		theSack.push_back(item);
	}
	T getOut() {
		if (empty()) {
			throw std::logic_error{"Empty Sack"};
		}
		auto index = static_cast<size_type>(rand() % size());
		T retval{theSack.at(index)};
		theSack.erase(theSack.begin() + index);
		return retval;
	}
};

#endif /* SACK_H_ */
