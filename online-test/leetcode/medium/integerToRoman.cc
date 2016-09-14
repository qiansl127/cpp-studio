/*
* # 12
* Integer to Roman
*/

#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    string romanToInteger(int num) {
        string unit[4][9] = {
            {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"M", "MM", "MMM", "", "", "", "", "", ""}
        };
        string res = "";
        int remainder = 0;
        for (int i = 0; num !=0; i++) {
            remainder = num % 10;
            if (remainder > 0) res = unit[i][remainder-1] + res;
            num /= 10;
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    Solution *s = new Solution();
    if (argc > 1) {
        cout << s->romanToInteger(atoi(argv[1])) << endl;
    } else {
        cout << s->romanToInteger(45) << endl;
    }
    delete s;
    return 0;
}
