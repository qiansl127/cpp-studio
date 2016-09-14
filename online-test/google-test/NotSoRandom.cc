/*
 * For google test
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
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

void insert(map<int, double>& m, int k, double v) {
  map<int, double>::iterator iter = m.find(k);
  if (iter == m.end()) {
    m.insert(pair<int, double>(k, v));
  } else {     
    iter->second += v;
  }
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
      int N(a[0]), X(a[1]), K(a[2]), A(a[3]), B(a[4]), C(a[5]);
      map<int, double> imap;
      imap.insert(pair<int, double>(X, 1.0));

      for (int j(1); j <= N; j++) {
        map<int, double> imap1;
        for (map<int, double>::iterator iter = imap.begin(); iter != imap.end(); iter++) {
          int X1 = iter->first & K;
          int X2 = iter->first | K;
          int X3 = iter->first ^ K;
          insert(imap1, X1, iter->second * A / 100.0);
          insert(imap1, X2, iter->second * B / 100.0);
          insert(imap1, X3, iter->second * C / 100.0);
        }
        imap = imap1;
      }
      
      double res(0.0);
      for (map<int, double>::iterator iter = imap.begin(); iter != imap.end(); iter++) {
        res += iter->first * iter->second;
      }
      cout.setf(ios::fixed);
      cout.precision(10);
      cout << "Case #" << i << ": " <<  res << endl;
      i++;
    }
    infile.close();
  }

  return 0;
}
