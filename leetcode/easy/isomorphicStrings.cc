/*
* # 205
* Isomorphic Strings
*/

#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char la[128], lb[128];
        for (int i = 0; i < 128; i++ ) lb[i] = (la[i] = 0);
        for (int i = 0; i < s.length(); i++) {
            char tick = la[s[i]];
            char tack = lb[t[i]];
            if (tick) {
                if (t[i] != tick) return false;
            }
            if (tack) {
                if (s[i] != tack) return false;
            }
            la[s[i]] = t[i];
            lb[t[i]] = s[i];
        }
        return true;
    }
};

int main() {
    Solution *s = new Solution();
    s->isIsomorphic("egg", "add") ? cout << "True\n" : cout << "False\n";
    s->isIsomorphic("foo", "bar") ? cout << "True\n" : cout << "False\n";
    s->isIsomorphic("title", "paper") ? cout << "True\n" : cout << "False\n";
    delete s;
    return 0;
}
