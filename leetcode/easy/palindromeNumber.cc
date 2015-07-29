/*
* # 9 
* Palindrome Number
*/

#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) return true;
        // unsigned int int_min = 0x80000000;
        // if ((unsigned int) x == int_min) return false;
        // if (x < 0) return isPalindrome(-x);
        if (x < 0) return false;
        int a[31];
        for (int i = 0; i < 31; i++) a[i] = -1;
        for (int i = 0; i < 31 && x != 0; i++) {
            a[i] = x % 10;
            x = x / 10;
        }
        int left(0), right(30);
        while (a[right] == -1) right--;
        while (left < right) {
            if (a[left] != a[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->isPalindrome(13131) << endl;
    cout << s->isPalindrome(-2147483648) << endl;
    cout << s->isPalindrome(-2147447412) << endl;
    delete s;
    return 0;
}
