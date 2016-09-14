/*
 * This file is created by Frank Qian, 2016.
 *
 */

#include "Array.h"

#include <iostream>

int main()
{
  Array<int> array(8);
  array.set(1019);
  array.print();
  std::cout << std::endl;
  
  Array<int> array2(8);
  array2 = array;
  array2.print();
  std::cout << std::endl;
  
  return 0;
}
