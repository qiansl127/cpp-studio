/*
* # 202
* Happy Number
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        vector<int> ivec;
        ivec.push_back(n);
        while (true) {
            int sum = 0;
            while (n > 0) {
                int t = n % 10;
                n = n / 10;
                sum += t*t;
            }
            if (1 == sum) return true;
            for (int i = 0; i < ivec.size(); i++) {
                if (sum == ivec[i]) return false;
            }
            ivec.push_back(sum);
            n = sum;
        }   
    }
};

int main() {
    Solution *s = new Solution();
    s->isHappy(19) ? cout << "True\n" : cout << "False\n";
    delete s;
    return 0;
}
