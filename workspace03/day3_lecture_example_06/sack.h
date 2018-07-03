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


template<typename T>
struct Sack<T *> {
	~Sack() = delete;
};


template<typename T> class Sack;

template<>
class Sack<char const *> {
	using SackType = std::vector<std::string>;
	using size_type = SackType::size_type;
	SackType theSack;
public:
	// no explicit  ctor / dtor  required
	bool empty() const {
		return theSack.empty();
	}
	size_type size() const {
		return theSack.size();
	}
	void putInto(char const *item) {
		theSack.push_back(item);
	}
	std::string getOut() {
		if (empty()) {
			throw std::logic_error { "empty Sack" };
		}
		std::string result = theSack.back();
		theSack.pop_back();
		return result;
	}
};



#endif /* SACK_H_ */
