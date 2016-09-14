#include <iostream>
using namespace std;

const int cint = 7;

template <typename T, int N>
T print(){
  T t(97);
  cout << t << " " << N << endl;
  return t;
}

int main() {
  print<int, 2>();
  print<char, cint>();
  return 0;
}
