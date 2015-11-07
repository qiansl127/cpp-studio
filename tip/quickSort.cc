/**
 * This file describes the c++ implementation of quick sort
 *
 */

#include<iostream>
using namespace std;

int pivot(int* array, int left, int right) {
  int key = array[left];
  int i = left, j = right-1;
  while (i < j) {
    while (i < j && key <= array[j]) j--;
    array[i] = array[j];
    while (i < j && key >= array[i]) i++;
    array[j] = array[i];
  }
  array[i] = key;
  return i;
}

void quickSort(int* array, int left, int right) {
  if (left < right) {
    int middle = pivot(array, left, right);
    quickSort(array, left, middle);
    quickSort(array, middle + 1, right);
  }
}

int main() {
  int array[] = {3, 8, -3, 2, 7, 0, -1};
  quickSort(array, 0, 7);
  for (int i = 0; i < 7; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  return 0;
}
