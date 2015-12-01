/*
* # 10
* Regular Expression Matching
* '*' stands for zero or more of the preceding char, '.' stands for any single char
*/

#include<iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.size() == 0) return s.size() == 0;
        
        if (p[1] != '*') {
            return ((p[0] == s[0]) || (p[0] == '.' && s.size() > 0)) && isMatch(s.substr(1), p.substr(1));
        }
        
        while (p[0] == s[0] || (p[0] == '.' && s.size() > 0)) {
            if (isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }
        
        return isMatch(s, p.substr(2));
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->isMatch("aab",".*") << endl;
    cout << s->isMatch("aab","c*a*b") << endl;
    delete s;
    return 0;
}
