/*
* # 8
* String to Integer
*/

#include<iostream>
using namespace std;

class Solution {
private:
    const static int maxInt = 2147483647;
    const static int minInt = -2147483648;
public:
    int myAtoi(string str) {
        if (str.length() == 0) return 0;
        if (str.length() > 1) {
            string sub = str.substr(1, str.length() - 1);
            if (str[0] == ' ') return myAtoi(sub);
            if (str[0] == '+') return calc(sub);
            if (str[0] == '-') return calc(sub, -1);
        }
        return calc(str);
    }
    int calc(string str, int type = 1) {
        int res = 0;
        if (type > 0) {
            for (int i = 0; i < str.length(); i++) {
               int gap = str[i] - '0';
               if (gap < 0 || gap > 9) return res;
               if (res > maxInt/10) return maxInt;
               if (maxInt - 10*res <= gap) return maxInt;
               res = 10*res + gap;
            }
        } else {
            for (int i = 0; i < str.length(); i++) {
               int gap = str[i] - '0';
               if (gap < 0 || gap > 9) return (0-res);
               if (res > maxInt/10) return minInt;
               if (maxInt - 10*res <= gap - 1) return minInt;
               res = 10*res + gap;
            }

        }
        return (type > 0)?res:(0-res);
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->myAtoi("+-2") << endl;
    cout << s->myAtoi(" -2") << endl;
    cout << s->myAtoi("    10522545459") << endl;
    cout << s->myAtoi("-2147483648") << endl;
    delete s;
    return 0;
}
