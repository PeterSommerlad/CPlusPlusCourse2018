#include <utility>
#include <stdexcept>
#include <thread>
#include <iostream>

struct scoped_thread {
  scoped_thread(std::thread && t)
      : the_thread{std::move(t)} {
    if (!the_thread.joinable())
      throw std::logic_error{"no thread"};
  }
  ~scoped_thread() {
    the_thread.join();
  }
private:
  std::thread the_thread;
};

int main() {
  scoped_thread t{std::thread{
    [] {std::cout << "Hello Thread"<< std::endl;}  
  }};
  std::cout << "Hello Main" << std::endl;
}
