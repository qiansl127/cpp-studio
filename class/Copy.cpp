/*
 * This case display some copy issues in C++ 
 * Copy by value vs copy by reference
 */

#include<iostream>
#include<map>
using namespace std;

class Node {
private:
  int val;
public:
  Node(): val(0) {}
  Node(int v): val(v) {}
  int getVal();
  void setVal(int v);
};

int Node::getVal() {
  return val;
}
void Node::setVal(int v) {
  this->val = v;
}

int main() {
  Node a1(1);
  // Copy by value (call default copy constructor)
  Node a2(a1);
  a2.setVal(2);
  cout << a1.getVal() << " " << a2.getVal() << endl;

  Node* b1 = new Node(1);
  // Copy by reference
  Node* b2 = b1;
  // Copy by value
  Node b3 = *b1;
  // Copy by reference
  Node& b4 = *b1;
  b2->setVal(2);
  b4.setVal(4);
  cout << b1->getVal() << " " << b2->getVal() << " " << b3.getVal() << " " << b4.getVal() << endl;
  delete b1;

  map<char, int> imap;
  imap.insert(pair<char, int>('a', 1));
  map<char, int> imap2;
  // Copy by value
  imap2 = imap;
  imap2.insert(pair<char, int>('b', 2));
  cout << imap.size() << " " << imap2.size() << endl;

  return 0;
}
