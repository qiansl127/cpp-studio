#include <iostream>
using namespace std;

//void func(int a[]) {
void func1(int *a) {
  cout << "-> " << a[1] << endl << endl;
}

//void func2(int b[][4]) {
void func2(int (*b)[4]) {  // pointer to array: int[4]
//WRONG: void func2(int *b[4]) {
//WRONG: void func2(int **b) {
  cout << "-> " << b[1][2] << endl << endl;
}

void func3(int* c[]) {  // array stores pointer
  cout << "-> " << c[1][2] << endl << endl;
}

int main() {
  int a[] = {0, 1, 2, 3};
  cout << a << " " << *(a + 0) << endl;
  cout << a[2] << " " << *(a + 2) << endl;
  func1(a);
  
  int b[3][4] = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11} 
  };
  cout << b << " " << *(*(b + 0) + 0) << endl;
  cout << b[1][2] << " " << *(*(b + 1) + 2) << endl;
  func2(b);
  
  int *c[3];  // int* (c[3])
  c[0] = new int[4];
  c[1] = new int[4];
  c[2] = new int[4];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      c[i][j] = i*4 + j;
    }
  }
  cout << c << " " << *(*(c + 0) + 0) << endl;
  cout << c[1][2] << " " << *(*(c + 1) + 2) << endl;
  func3(c);
  
  delete[] c[0];
  delete[] c[1];
  delete[] c[2];
  
  return 0;
}
