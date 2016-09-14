/**
*  This case shows that the copy constructor will be called if using pass-by-value.
*
**/

#include<iostream>
 
class Widget {
public:
  Widget(){}
  Widget(const Widget& rhs){
    std::cout << "in copy constructor\n";
  }
};
 
void display(Widget w){
  std::cout << "in display\n";
}
 
void display2(const Widget& w){
  std::cout << "in second display\n";
}
 
int main() {
  Widget wd;
  display(wd);
  display2(wd);
  return 0;
}
