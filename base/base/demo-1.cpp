/**
*  This file describes the pointer of a pointer.
*
**/

#include <iostream>
using namespace std;
 
bool func2(int** A) {
  //不能改变A（二级指针的地址）
 
  *A = new int(5);
  //可以改变*A，代表改变二级指针的值（一级指针的地址）
 
  cout << **A << endl;
  **A = 3;
  //可以改变**A，代表改变一级指针的值（一级指针指向内存区域的地址）
 
  cout << **A << endl; //int
  cout << *A << endl;  //int*
  cout << A << endl;   //int**
  return true;
}
 
int main() {
  int* a;
  func2(&a);
  //取地址符&，对a取地址，将地址值传进去，这个地址不为空，地址指向的值为空，将在函数体内new
  //&a是二级指针，a是一级指针（a指向的值是int类型）
 
  cout << "\nAfter func2(&a)\n";
  cout << &a << endl; //int**
  cout << a << endl; //int*
  cout << *a <<endl; //int
  cout << "************\n\n";
 
  int** b = new (int*);
  /**
  *  在以指针作为参数的函数中，指针的地址值不能改变，只能改变该地址指向的值
  *  所以不能传空指针，如果指针为空，即指针的值（指针指向的地址）为空，传入函数后继续为空，除非在函数体内进行new操作，否则不能直接赋值
  *  现在，**b是一级指针，*b是二级指针，b是三级指针
  *  在这里也就是，只有三级指针的值（二级指针的地址）不为空，才能将二级指针的值进行改变（即函数中的new操作），所以要在函数体外对三级指针进行new操作
  *
  **/

  func2(b);
  cout << "\nAfter func2(b)\n";
  cout << &b << endl;  //int***
  cout << b << endl;  //int**
  cout << *b << endl;   //int*
  cout << **b << endl;    //int
  cout << "************\n\n";
 
  delete a;
  delete *b;
  delete b;

  int******** c = new (int*******);
  *c = new (int******);
  **c = new (int*****);
  ***c = new (int****);
  ****c = new (int***);
  *****c = new (int**);
  ******c = new (int*);
  *******c = new int(123);

  cout << ********c << endl;

  delete *******c;
  delete ******c;
  delete *****c;
  delete ****c;
  delete ***c;
  delete **c;
  delete *c;
  delete c;
 
  return 0;
}
