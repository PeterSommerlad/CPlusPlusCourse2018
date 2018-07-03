#include "MyMin.h"
#include <string>

namespace MyMin {
char const * min(char const * a, char const * b) {
  return std::string(a) < std::string(b) ? a : b;
}
}
