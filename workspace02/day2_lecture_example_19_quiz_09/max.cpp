#include <iostream>
#include <string>


std::string const & max(
    std::string const & left,
    std::string const & right) {
  return (left > right) ? left : right;
}

int main() {
  std::string const & larger = max("a", "astringtoolargeforsmallstringoptimization");
  std::cout << "larger is: " << larger;
}
