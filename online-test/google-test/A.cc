/*
 * For google test
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
using namespace std;

string filename("A-small-attempt2.in");

int main() {
  string line;
  ifstream infile(filename);
  int T;

  if (infile) {
    if (getline(infile, line)) {
      T = stoi(line);
    }
    int i(1);
    while (i <= T && getline(infile, line)) {
      int N = stoi(line);
      int j(1);
      map<string, int> imap;
      while (j <= N && getline(infile, line)) {
        set<char> iset;
        for (int k = 0; k < line.size(); k++) {
          if (line[k] != ' ') iset.insert(line[k]);
        }
        imap.insert(pair<string, int>(line, iset.size()));
        j++;
      }
      map<string, int>::iterator it0 = imap.begin();
      int max(0);
      for (map<string, int>::iterator it = imap.begin(); it != imap.end(); it++) {
        if (it->second > max) {
          it0 = it;
          max = it->second;
        } else if (it->second == max) {
          string s0 = it0->first;
          string s = it->first;
          int ii(0), ij(0);
          while (s0[ii] == s[ij] && ii < s0.size() && ij < s.size()) {
            ii++;
            ij++;
          }
          if (s0[ii] > s[ij]) it0 = it;
        }
      }
      cout << "Case #" << i << ": " << it0->first << endl;
      i++;  
    }
    infile.close();

  }

  return 0;
}
