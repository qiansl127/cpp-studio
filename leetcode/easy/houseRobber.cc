/*
* # 198
* House Robber
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int best0 = 0, best1 = 0, temp = 0;
        for (int i = 0; i < nums.size(); i++) {
            temp = best0;
            best0 = max(best0, best1);
            best1 = temp + nums[i];
        }
        return max(best0, best1);
    }
};

int main() {
    Solution *s = new Solution();
    int arr[] = {2, 3, 2};
    size_t count = sizeof(arr)/sizeof(int);
    vector<int> ivec(arr, arr + count);
    cout << s->rob(ivec) << endl;
    delete s;
    return 0;
}
