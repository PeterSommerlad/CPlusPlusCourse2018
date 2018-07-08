#ifndef WRAPPER_H_
#define WRAPPER_H_

template <typename T>
struct Wrapper {
  T wrapped{};
  void set(T const & value) {
    wrapped.release();
    wrapped = value;
  }
};




#endif /* WRAPPER_H_ */
