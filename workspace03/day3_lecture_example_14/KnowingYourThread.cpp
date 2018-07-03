#include <thread>

#include <iostream>

int main() {
  using std::cout;
  using std::endl;
  using namespace std::chrono_literals;

  std::thread t { [] {
    std::this_thread::yield();
    cout << "Hello ID: "
         << std::this_thread::get_id()
         << endl;
    std::this_thread::sleep_for(10ms);
  }};
  cout << "main() ID: "
       << std::this_thread::get_id()
       << endl;
  cout << "t.get_id(): " 
       << t.get_id()
       << endl;
  t.join();
}
