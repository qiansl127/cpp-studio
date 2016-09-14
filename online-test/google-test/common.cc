/*
 * For google test
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

string filename("NotSoRandom.in");

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
      int a[6];
      split(line, ' ', a);
      cout << a[0] << endl;
      i++;  
    }
    infile.close();
  }

  return 0;
}
