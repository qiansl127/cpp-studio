/**
* Basic knowledge about pointer.
*
**/

#include<iostream>

void func(int* p) {
//按指针传递，可以改变*p，但不能改变p
  (*p)--;
  std::cout << "[In func] " << *p << std::endl;
}

int main() {
  int* p = new int(5);
  std::cout << *p << std::endl;  //解引用，值5
  std::cout << p << std::endl;  //值5的地址，指针p的值
  std::cout << &p << std::endl;  //指针p的地址

  func(p);  //传指针进去，即传值的地址

  int q = *p;
  func(&q);

  delete p;
}
