/*
* # 29
* Divide Two Integers
*/

#include<iostream>
#include<limits.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned long dd = (dividend < 0) ? (0 - dividend) : dividend;
        unsigned long dr = (divisor < 0) ? (0 - divisor) : divisor;
        if (dividend == INT_MIN) {
            dd = INT_MAX;
            dd++;
        }
        if (divisor == INT_MIN) {
            dr = INT_MAX;
            dr++;
        }
        if (dd < dr) return 0;

        int sign(1);
        if (dividend < 0) sign = 0 - sign;
        if (divisor < 0) sign = 0 - sign;

        int step(0);
        unsigned long res(0), dr0(dr);
        
        while (dd >= dr0) {
            step = 0;
            dr = dr0;
            while (dr <= dd) {
                dr <<= 1;
                step++;
            }
            res += ((unsigned long) 1 << (step-1));
            dd -= (dr >> 1);
        }
        if (sign < 0) {
            return (0 - res);
        } else {
            if (res >= INT_MAX) return INT_MAX;
            return res;
        }
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->divide(-1, 1) << endl;
    cout << s->divide(INT_MIN, -1) << endl;
    cout << s->divide(INT_MIN, 1) << endl;
    cout << s->divide(INT_MIN, INT_MIN) << endl;
    delete s;
    return 0;
}
