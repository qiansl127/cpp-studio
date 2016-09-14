/*
* # 43
* Multiply Strings
*/

#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int m(num1.size()), n(num2.size());
        if (m < 1 || n < 1) return "";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res(m + n, '0');
        for (int i = 0; i < m; i++) {
            int last(0);
            for (int j = 0; j < n; j++) {
                int cur = (num1[i] - '0') * (num2[j] - '0') + last + res[i+j] - '0';
                res[i+j] = cur % 10 + '0';
                last = cur / 10;
            }
            if (last != 0) res[i+n] += last;
        }
        reverse(res.begin(), res.end());
        int count(0);
        while (res[count] == '0' && count < res.size()) count++;
        if (count == res.size()) return "0";
        return res.substr(count, res.size() - count);
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->multiply("999999999", "999999999") << endl;
    delete s;
    return 0;
}
