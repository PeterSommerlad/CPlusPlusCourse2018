
#include <iostream>

#include <thread>

struct HelloFunctor {
  void operator()() const {
    std::cout << "Functor" << std::endl;
  }
};

void helloFunction() {
  std::cout << "Function" << std::endl;
}

int main() {
  std::thread function { helloFunction };
  std::thread functor { HelloFunctor{} };
  std::thread lambda {
    [] { std::cout << "Lambda" << std::endl; }
  };
  std::cout << "Main" << std::endl;
  lambda.join();
  functor.join();
  function.join();
}
