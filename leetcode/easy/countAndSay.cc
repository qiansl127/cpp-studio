/*
* # 38
* Count And Say
*/

#include<iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s("1");
        for (int i = 1; i < n; i++) {
            s = change(s);
        }
        return s;
    }
    string change(string s) {
        string res("");
        char t(s[0]);
        int i(1), count(1);
        while (i < s.size()) {
            if (t == s[i]) {
                count++;
            } else {
                res += count + '0';
                res += t;
                count = 1;
                t = s[i];
            }
            i++;
        }
        res += count += '0';
        res += t;
        return res;
    }
};

int main() {
    Solution *s = new Solution();

    cout << s->countAndSay(18) << endl;

    delete s;
    return 0;
}
