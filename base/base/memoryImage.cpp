#include <iostream>
using namespace std;

int main() {
  static int sa1 = 7;
  
  int* h1 = new int(7);
  int* h2 = new int(8);
  int* h3 = new int(9);
  
  int s1 = 9;
  int s2 = 8;
  int s3 = 7;
  
  cout << &sa1 << " " << sa1 << endl;
  
  cout << h1 << " " << *h1 << endl;
  cout << h2 << " " << *h2 << endl;
  cout << h3 << " " << *h3 << endl;
  
  cout << &s1 << " " << s1 << endl;
  cout << &s2 << " " << s2 << endl;
  cout << &s3 << " " << s3 << endl;
  
  delete h1;
  delete h2;
  delete h3;
  
  return 0;
}
