#ifndef SRC_MIN_H_
#define SRC_MIN_H_


template <typename Head, typename...T>
decltype(auto) min(Head const & head, T const &...tail) {
	if constexpr (sizeof...(tail)) {
		decltype(auto) tailMin = min(tail...);
		return (head < tailMin) ? head : tailMin;
	}
	return head;
}


#endif /* SRC_MIN_H_ */
