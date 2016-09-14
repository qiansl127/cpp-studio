/*
* # 20
* Valid Parentheses
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> cvec;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case '(':
                case '[':
                case '{':
                    cvec.push_back(s[i]);
                    break;
                case ')':
                    if (cvec.empty() || cvec.back() != '(') return false;
                    cvec.pop_back();
                    break;
                case ']':
                    if (cvec.empty() || cvec.back() != '[') return false;
                    cvec.pop_back();
                    break;
                case '}':
                    if (cvec.empty() || cvec.back() != '{') return false;
                    cvec.pop_back();
                    break;
                default:
                    ;
            }
        }
        return (cvec.size() == 0);
    }
};

int main() {
    Solution *s = new Solution();
    string s1("{dd[e]ll(o)dd}");
    string s2("]");
    cout << s2 + " is ";
    if (s->isValid(s2)) {
        cout << "valid" << endl;
    } else {
        cout << "invalid" << endl;
    }
    delete s;
    return 0;
}
