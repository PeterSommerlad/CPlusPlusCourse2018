#include <iostream>
#include <thread>

int main() {
  std::thread lambda {
    [] {std::cout << "Lambda" << std::endl; }
  };
  std::cout << "Main" << std::endl;
}
