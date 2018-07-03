#ifndef SACK_H_
#define SACK_H_

#include <initializer_list>
#include <stdexcept>
#include <vector>

template<typename T, template<typename...> typename Container = std::vector>
class Sack {
	using SackType = Container<T>;
	using size_type = typename SackType::size_type;
	SackType theSack{};

public:
//	Sack() = default;

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


	template <typename Elt>
	explicit operator std::vector<Elt>() const {
		return std::vector<Elt>(begin(theSack), end(theSack));
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
		auto it = begin(theSack);
		advance(it, index);
		T retval{*it};
		theSack.erase(it);
		return retval;
	}
};

template <typename Iter>
Sack(Iter begin, Iter end) -> Sack<typename std::iterator_traits<Iter>::value_type>;


#endif /* SACK_H_ */
