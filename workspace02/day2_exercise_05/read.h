#ifndef READ_H_
#define READ_H_

#include <istream>

//Base case version
//void read(std::istream & in) {}

//if constexpr version
//template<typename Head, typename...T>
//void read(std::istream & in, Head & head, T &...pack) {
//  in >> head;
//  if constexpr(sizeof...(pack)) {
//	  read(in, pack...);
//  }
//}

//fold expression version
template<typename...T>
void read(std::istream & in, T &...pack) {
  (in >> ... >> pack);
}



#endif /* READ_H_ */
