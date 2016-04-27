/*
 * How to use objects to manage resources
 *
 */

#include<iostream>
using namespace std;

class B {
private:
  int v;
public:
  B(): v(0) {}
  B(int val): v(val) {}
  int getV() { return v; }
  ~B() {
    cout << "In destructor of B, the val in b is:" << this->getV() << endl;
  }
};

class A {
private:
  B* b;
public:
  A() {}
  A(B* val): b(val) {}
  ~A() {
    cout << "In destructor of A, the val in b is:" << b->getV() << endl;
    delete b;
  }

};

int main() {
  A(new B(7));
  // the destructor of auto_ptr will delete the object it pointing to automatically
  auto_ptr<B> pB(new B(8));
};
