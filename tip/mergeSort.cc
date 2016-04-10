/**
 * This file describes the c++ implementation of merge sort and bottom-up merge sort
 *
 */

#include<iostream>
using namespace std;

void merge(int* A, int l, int m, int r) {
  // merge A[l, m) and A[m, r)
  int* B = new int[r-l];
  int i(l), j(m), k(0);
  while (i < m && j < r) {
    B[k++] = (A[i] <= A[j]) ? A[i++] : A[j++];
  }
  if (i == m) {
    while (j < r) {
      B[k++] = A[j++];
    }
  } else {
    while (i < m) {
      B[k++] = A[i++];
    }
  }
  for (int t1 = l, t2 = 0; t1 < r; t1++, t2++) {
    A[t1] = B[t2];
  }
  delete[] B;
}

void mergeSort(int* A, int l, int r) {
  // The bound [l, r), so when l equals (r-1), there is only one element
  if (l < r - 1) {
    int m = (l + r) / 2;
    mergeSort(A, l, m);
    mergeSort(A, m, r);
    merge(A, l, m, r);
  }
}

void bottomUpSort(int* A, int size) {
  int t(1);
  while (t < size) {
    int s(t), i(0);
    t = 2 * s;
    while (i + t <= size) {
      merge(A, i, i + s, i + t);
      i += t;
    }
    if (i + s < size) merge (A, i, i + s, size);
  }
}

int main() {
  int A[] = {9, 4, 5, 2, 1, 7, 4, 6};
  //mergeSort(A, 0, 8);
  bottomUpSort(A, 8);
  for (int i = 0; i < 8; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
  return 0;
}
