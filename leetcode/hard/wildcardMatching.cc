/*
* # 44
* Wildcard Matching
* '*' stands for any sequence of chars inluding empty, '?' stands for any single char
*/

#include<iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.size() == 0) return s.size() == 0;
        
        // res[i] after loop j means s[0, i) is match with p[0, j]
        const int res_size(s.size() + 1);
        bool res[res_size];
        for (int i = 0; i < res_size; i++) res[i] = false;
        res[0] = true;
        
        for (int j = 0; j < p.size(); j++) {
            if (p[j] != '*') {
                for (int i = s.size() - 1; i >= 0; i--) {
                    res[i + 1] = res[i] && (p[j] == '?' || p[j] == s[i]);
                }
            } else {
                int i(0);
                while (i <= s.size() && !res[i]) i++;
                for (; i <= s.size(); i++) res[i] = true;
            }
            res[0] = res[0] && p[j] == '*';
        }
        
        return res[s.size()];
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->isMatch("ab", "?*") << endl;
    delete s;
    return 0;
}
