/**
*  Static variable defined in a function.
*
**/

#include<iostream>

class T {
public:
  T();
  void add();
  void display();
private:
  int t;
};

T::T(): t(0) {}
void T::add() {
  t++;
}
void T::display() {
  std::cout << this->t << std::endl;
}

int main() {
  T& get();

  T& t1 = get();
  t1.display();
  t1.add();
  t1.display();

  T& t2 = get();
  t2.display();

  return 0;
}

T& get() {
  static T temp;
  return temp;
}
