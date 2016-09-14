#ifndef ARRAY_H
#define ARRAY_H
/*
 * This file is created by Frank Qian, 2016.
 *
 */

template <typename T>
class Array
{
public:
  Array(unsigned n): size(n) { v = new T[size]; }
  ~Array() { delete[] v; }
  Array(const Array&) = delete;
  Array& operator=(const Array&);
  
  Array(Array&&) noexcept = delete;
  Array& operator=(Array&&) noexcept = delete;
  
  void set(T);
  void print();
private:
  unsigned size;
  T* v;
};

#include "Array.tpp"
#endif
