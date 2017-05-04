#include <iostream>

class X
{
public:
  int a;
  X(int _a): a {_a} {}
  void func();
};

void X::func()
{
  std::cout << "Func called!" << std::endl;
}

int main()
{
  int X::*p1 = &X::a;
  void (X::*p2)() = &X::func;

  X x1 {7};
  std::cout << x1.*p1 << std::endl;
  (x1.*p2)();

  X *px = &x1;
  std::cout << px->*p1 << std::endl;
  (px->*p2)();
}
