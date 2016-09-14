/*
* # 13
* Roman to Integer
*/

#include<iostream>
using namespace std;

class Solution {
public:
    int romanToInteger(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            char next = s[i+1];
            switch (s[i]) {
            case 'I':
                (next != 'I' && next != '\0') ? res -= 1 : res += 1;
                break;
            case 'V':
                res += 5;
                break;
            case 'X':
                (next == 'L' || next == 'C' || next == 'D' || next == 'M') ? res -= 10 : res += 10;
                break;
            case 'L':
                res += 50;
                break;
            case 'C':
                (next == 'D' || next == 'M') ? res -= 100 : res += 100;
                break;
            case 'D':
                res += 500;
                break;
            case 'M':
                res += 1000;
                break;
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    Solution *s = new Solution();
    if (argc > 1) {
        cout << s->romanToInteger(string(argv[1])) << endl;
    } else {
        cout << s->romanToInteger("XLV") << endl;
    }
    delete s;
    return 0;
}
