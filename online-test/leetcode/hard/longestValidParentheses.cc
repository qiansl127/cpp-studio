/*
* # 32
* Longest Valid Parentheses
*/

#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack< pair<int, char> > istack;
        int maxLen(0);
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case '(':
                    istack.push(pair<int, char>(i, '('));
                    break;
                case ')':
                    if (!istack.empty() && istack.top().second == '(') {
                        istack.pop();
                        if (!istack.empty()) {
                            maxLen = max(maxLen, i - istack.top().first);
                        } else {
                            maxLen = max(maxLen, i + 1);
                        }
                    } else {
                        istack.push(pair<int, char>(i, ')'));
                    }
                    break;
                default:
                    ;
            }
        }
        return maxLen;
    }
};

int main() {
    Solution *s = new Solution();

    cout << s->longestValidParentheses(")()()(") << endl;

    delete s;
    return 0;
}
