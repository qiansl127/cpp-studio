#include <iostream>
using namespace std;

class Base
{
public:
  Base(int i0) { i = i0; }
  virtual void get() {}
  virtual ~Base() { cout << "b\n"; }
  virtual void get2() {}
protected:
  int i;
};

class Derived: public Base
{
public:
  Derived(int i0): Base(i0) {}
  ~Derived() { cout << "d\n"; }
  void get() { cout << "in d get\n"; }
  void get2() { cout << "in d get2\n"; }
};

int main() {
  typedef void (*Func)();
    
  Derived d(7);
  Func f1 = (Func)*((long *)*(long *)(&d));
  f1();
  f1 = (Func)*((long *)*(long *)(&d) + 3);
  f1();

  return 0;
}
