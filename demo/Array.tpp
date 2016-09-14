/*
 * This file is created by Frank Qian, 2016.
 *
 */

#include "Array.h"

#include <assert.h>
#include <iostream>

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& array)
{
  assert(this->size == array.size);
  for (unsigned i = 0; i < this->size; i++)
  {
    this->v[i] = array.v[i];
  }
  return *this;
}

template <typename T>
void Array<T>::set(T t)
{
  for (unsigned i = 0; i < size; i++)
  {
    v[i] = t;
  }
}

template <typename T>
void Array<T>::print()
{
  for (unsigned i = 0; i < size; i++)
  {
    std::cout << v[i] << " ";
  }
}
