/*
 * C++ 11
 * Test swap by move
 *
 */

#include <iostream>
#include <vector>
using namespace std;

template<class T> 
void swapByCopy(T& a, T& b) 
{
  T tmp(a);
  a = b; 
  b = tmp;
}

template<class T> 
void swapByMove(T& a, T& b) 
{
  T tmp(std::move(a));
  a = std::move(b); 
  b = std::move(tmp);
} 

template<class T>
void print(vector<T>& ivec0, vector<T>& ivec1) {
  cout << &ivec0 << " " << &ivec0[0] << " " << ivec0[0] << "; "
       << &ivec1 << " " << &ivec1[0] << " " << ivec1[0] << endl;
}

int main() {
  cout << "Swap by move and by copy\n";

  vector<int> ivec0(1, 1);
  vector<int> ivec1(1, 2);

  print(ivec0, ivec1);

  swapByCopy(ivec0, ivec1);
  print(ivec0, ivec1);

  swapByMove(ivec0, ivec1);
  print(ivec0, ivec1);

  /*
   * The address of ivec0 and ivec1 won't change in swap.
   * The address of int array will change if swap by move.
   * Vector has its move constructor.
   *
   */

  return 0;
}
