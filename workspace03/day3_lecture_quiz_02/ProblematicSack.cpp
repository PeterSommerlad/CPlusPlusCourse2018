#include <vector>

template <typename T>
class Sack {
  using SackType = std::vector<T>;
  using size_type = SackType::size_type;
  SackType theSack{};
};
