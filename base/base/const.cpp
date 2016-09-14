/**
*  This file is about the const pointer
*
**/

#include<iostream>
int main() {
  char greeting[] = "yellow\n";
  char* const cp = greeting;
  //const pointer, non-const data
  const char* const ccp = greeting;
  //const pointer, const data

  std::cout << greeting << cp << ccp << std::endl;

  greeting[0] = 'Y';
  std::cout << greeting << cp << ccp << std::endl;

  cp[0] = 'B';
  std::cout << greeting << cp << ccp << std::endl;

  //ccp[0] = 'Y';
  //error: read-only variable is not assignable

  return 0;
}
