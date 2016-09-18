#include <iostream>
using namespace std;

class Base
{
public:
  Base(int i0) { i = i0; }
  virtual int get() const { return i; }
protected:
  int i;
};

int main() {
  Base b(511);
  cout << b.get() << endl;
  
  cout << sizeof(long) << sizeof(long*) << sizeof(int*) << sizeof(Base*) << sizeof(char*) << endl;
  cout << sizeof(b) << " " << sizeof(int) << " " << sizeof(char) << endl;
  unsigned char* p = (unsigned char*)(&b);

  for (unsigned i = 0; i < sizeof(b); i++) {
      cout << i << " " << (long*)p << " " << *p - 0 << endl;
      p++;
  }
  
  return 0;
}
