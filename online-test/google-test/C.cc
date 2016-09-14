/*
 * For google test
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;

string filename("C-small-attempt0.in");

int* split(const string& s, char delim, int* A) {
  stringstream ss(s);
  string item;
  int i(0);
  while (getline(ss, item, delim)) {
    A[i++] = stoi(item);
  }
  return A;
} 

int main() {
  string line;
  ifstream infile(filename);
  int T;

  if (infile) {
    if (getline(infile, line)) {
      T = stoi(line);
    }
    int i(1);
    while (getline(infile, line) && i <= T) {
      int M = stoi(line);
      getline(infile, line);
      const int size = M + 1; 
      int a0[size];
      split(line, ' ', a0);

      double irr;
      if (M == 1) {
        irr = a0[1] * 1.0 / a0[0] - 1.0;
      } else if (M == 2) {
        double a = a0[0], b = 0 - a0[1], c = 0 - a0[2];
        irr = ((0 - b) + pow((b * b - 4 * a * c), 0.5)) / 2 / a - 1;
      }      
      cout.setf(ios::fixed);
      cout.precision(12);
      cout << "Case #" << i << ": " << irr << endl;
      i++;  
    }
    infile.close();
  }

  return 0;
}
