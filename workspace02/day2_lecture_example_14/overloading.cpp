#include <iostream>

struct S {};

void take(S && s) { //S && is an rvalue reference
  std::cout << "take(S &&)\n";
}

void take(S & s) { //S && is an lvalue reference
  std::cout << "take(S &)\n";
}

int main()
{
  S s{};
  take(S{});     //rvalue S
  take(s);       //lvalue S
  S const sc{};
  //take(sc);      //const lvalue S
}
