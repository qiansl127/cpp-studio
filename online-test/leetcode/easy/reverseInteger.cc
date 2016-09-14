/*
* # 7
* Reverse Integer
*/

#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if ((unsigned int)x == 0x80000000) return 0;
        if (x < 0) return (0 - reverse(-x));
        int res = 0;
        while (x != 0) {
            if (214748364.7 - res < x%10*0.1) return 0;
            res = 10*res + x%10;
            x = x / 10;
        }
        return res;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->reverse(1534236469) << endl;
    delete s;
    return 0;
}
