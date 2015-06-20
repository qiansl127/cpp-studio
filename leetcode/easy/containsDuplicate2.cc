/*
* # 219
* Contains Duplicate 2
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) return true;
        }
        return false;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<int> copy(nums);
        if (!containsDuplicate(copy)) return false;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size() && j <= i + k; j++) {
                if (nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution *s = new Solution();
    int arr[] = {1, 2, 1};
    size_t count = sizeof(arr)/sizeof(int);
    vector<int> nums(arr, arr + count);
    s->containsNearbyDuplicate(nums, 1) ? cout << "True\n" : cout << "False\n";
    delete s;
    return 0;
}
