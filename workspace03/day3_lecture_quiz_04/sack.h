#ifndef SACK_H_
#define SACK_H_

#include <iterator>
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
	  auto asVector() const {
	    return std::vector<T>(begin(theSack),
	                          end(theSack));
	  }

};

#endif /* SACK_H_ */
