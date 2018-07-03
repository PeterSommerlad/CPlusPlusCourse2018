#ifndef READ_H_
#define READ_H_

#include <istream>

template<typename...T>
void read(std::istream & in, T &...pack) {
  (in >> ... >> pack);
}



#endif /* READ_H_ */
