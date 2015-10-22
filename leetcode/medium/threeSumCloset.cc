/*
* # 16
* 3Sum Closet
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class Solution {
public:
    int threeSumCloset(vector<int>& nums, int target) {
        int min = INT_MAX;
        int res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int start = i + 1, end = nums.size() - 1; start < end; ) {
                int sum = nums[i] + nums[start] + nums[end];
                int diff = abs(sum - target);
                if (diff == 0) return sum;
                if (diff < min) {
                    min = diff;
                    res = sum;
                }
                (sum <= target)? start++ : end--;
            }
        }
        return res;
    }
};

int main() {
    Solution *s = new Solution();
    int array[] = {0, 1, 2};
    vector<int> v(array, array + sizeof(array)/sizeof(int));
    int res = s->threeSumCloset(v, 2);
    cout << res << endl;
    delete s;
    return 0;
}
