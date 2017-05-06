#include <iostream>
#include <memory>

class A
{
  int a;
public:
  A(int _a): a {_a} {}
  A(const A& rhs): a{rhs.a} { std::cout << "Copy Constructor" << std::endl; }
  A(A&& rhs): a{rhs.a} { std::cout << "Move Constructor" << std::endl; }
  int print() { return a; }
};

void foo(std::unique_ptr<A> p)
{
  std::cout << p->print() << " in foo" << std::endl;
}

void foo(A a) {
  std::cout << a.print() << " in foo" << std::endl;
}

void bar(A&& a) {
  std::cout << a.print() << " in bar" << std::endl;
}

int main()
{
  auto up = std::make_unique<A>(7);
  foo(std::move(up));

  A a {8};
  foo(a);
  foo(std::move(a));
  //bar(a);
  bar(std::move(a));
}
