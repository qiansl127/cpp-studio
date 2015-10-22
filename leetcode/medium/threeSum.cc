/*
* # 15
* 3Sum
*/

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector< vector<int> > res;
        for (int i = 0; i < nums.size(); i++) {
            int target = 0 - nums[i];
            for (int start = i + 1, end = nums.size() - 1; start < end; ) {
                int real = nums[start] + nums[end];
                if (target == real) {
                    vector<int> ivec;
                    ivec.push_back(nums[i]);
                    ivec.push_back(nums[start]);
                    ivec.push_back(nums[end]);
                    res.push_back(ivec);
                    start++;
                    while (nums[start] == nums[start-1]) start++;
                    end--;
                    while (nums[end] == nums[end+1]) end--;
                } else if (target > real) {
                    start++;
                } else {
                    end--;
                }
            }
            while(nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};

int main() {
    Solution *s = new Solution();
    int array[] = {-1, 0, 1, 2, -1, -4};
    vector<int> v(array, array + sizeof(array)/sizeof(int));
    vector< vector<int> > res = s->threeSum(v);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
             cout << res[i][j] << " ";
        }
        cout << endl;
    }
    delete s;
    return 0;
}
