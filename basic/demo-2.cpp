/**
*  This file describes the pointer of arrays.
*
**/

#include<iostream>
using namespace std;
 
void func(int** A) {
  *A = new int[1];
  (*A)[0] = 101;
  //数组下标的优先级大于解引用
}
 
void func2(int*** A) {
  *A = new int*[1];
  (*A)[0] = new int[2];             
  //维度不确定，一层一层new出来
 
  (*A)[0][0] = 88;
  (*A)[0][1] = 77;
}
 
void func3(int (**A)[2][3]) {            
//如果多维数组的二三维确定，就可以这样写
 
  *A = new int[1][2][3];             
  //只需要new一次
 
  (*A)[0][0][1] = 12;
}
 
int main() {
  int** a = new int*;
  func(a);
  cout << (*a)[0] << endl;
  delete[] *a;
  delete a;
 
  int*** b = new int**;
  func2(b);
  cout << (*b)[0][0] << " " << (*b)[0][1] << endl;
 
  delete[] *b[0];
  delete[] *b;
  delete b;
 
  int (**c)[2][3] = new (int (*)[2][3]);
  //c的类型为 int (**)[2][3]
  func3(c);                          
  //注意不能传空指针进去
 
  cout << (*c)[0][0][1] << endl;
  delete[] *c;
  delete c;
 
  //也可以这样写
  int (*cc)[2][3];
  func3(&cc);
  cout << cc[0][0][1] << endl;
  delete[] cc;

  cout<<"********************\n";
  //下面是不在函数内进行的多维数组新建
 
  int (*pa2)[2][3];
  pa2 = new int[1][2][3];    
  //数组的第一维如果不确定，二三维都确定，就可以这样写
 
  pa2[0][1][2] = 21;
  cout << pa2[0][1][2] << endl;
  delete[] pa2;
 
  int** pa = new int*[2];   
  //important! no (int*)[2]
  pa[0] = new int[2];     
  pa[1] = new int[3];     
  //数组的维数不确定，就可以一层一层new出来
 
  pa[0][1] = 21;
  pa[1][2] = 22;
  cout << pa[0][1] << " " << pa[1][2] << endl;
  delete[] pa[0];
  delete[] pa[1];
  delete[] pa;

  return 0;
}
