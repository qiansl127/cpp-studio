#include <iostream>
using namespace std;

int main() {
  //normal new/delete
  void* p = operator new(4);
  int* pi = static_cast<int*>(p);
  *pi = 2147483647;
  cout << p << " " << pi << " " << *pi << endl; 
  operator delete(p);

  //placement new/delete
  void* p2 = operator new(1, p);    //size_t, void*
  char* pi2 = static_cast<char*>(p2);
  *pi2 = 'f';
  cout << p2 << " " << reinterpret_cast<int*>(pi2) << " " << *pi2 << endl;
  operator delete(p2, p);    //void*, void*
  
  return 0;
}
