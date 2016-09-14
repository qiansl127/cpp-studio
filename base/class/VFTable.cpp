#include <iostream>

class Base {
public:
  virtual void f() { std::cout << "I am Base::f()" << std::endl; }
  virtual void g() { std::cout << "I am Base::g()" << std::endl; }
  virtual void h() { std::cout << "I am Base::h()" << std::endl; }
};

class Derive: public Base {
public:
 void virtual f1() { std::cout << "I am Derive::f1()" << std::endl; }
 void f2() { std::cout << "I am Derive::f2()" << std::endl; }
};

int main() {

  std::cout << sizeof(char) << " " << sizeof(char*) << std::endl;
  std::cout << sizeof(int)  << " " << sizeof(int*)  << std::endl;
  // int occupy 4 bits, but we need at lest 8 bits for address
  std::cout << sizeof(long)  << " " << sizeof(long*)  << std::endl;

  typedef void(*Fun)(void);
  Fun pf(NULL);

  Base b;
  std::cout << "address of the object : " << &b << std::endl;
  std::cout << "address of VF table   : " << (long*)(&b) << std::endl;
  std::cout << "address of first item : " << *(long*)(&b) << std::endl;
  std::cout << "address of first item : " << (long*)*(long*)(&b) << std::endl;
  pf = (Fun)*((long*)*(long*)(&b));
  pf();

  std::cout << std::endl;
  std::cout << "address of first item plus 1: " << (long*)*(long*)(&b) + 1 << std::endl;
  pf = (Fun)*((long*)*(long*)(&b) + 1);
  pf();

  Derive d;
  d.f1();

  Base* bb = new Derive();
  bb->f();

/* cannot be compilted:
 *
   bb->f1();
   bb->f2();
 */

  delete bb;

  return 0;
}
