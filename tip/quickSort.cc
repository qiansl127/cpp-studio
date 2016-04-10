/**
 * This file describes the c++ implementation of quick sort
 *
 */

#include<iostream>
using namespace std;

int pivot(int* A, int left, int right) {
  int key = A[left];
  int i = left, j = right-1;
  while (i < j) {
    while (i < j && key <= A[j]) j--;
    A[i] = A[j];
    while (i < j && key >= A[i]) i++;
    A[j] = A[i];
  }
  A[i] = key;
  return i;
}

void quickSort(int* A, int left, int right) {
  if (left < right) {
    int middle = pivot(A, left, right);
    quickSort(A, left, middle);
    quickSort(A, middle + 1, right);
  }
}

int main() {
  int A[] = {9, 4, 5, 2, 1, 7, 4, 6};
  quickSort(A, 0, 8);
  for (int i = 0; i < 8; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
  return 0;
}
