/*
* # 217
* Contains Duplicate
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
};

int main() {
    Solution *s = new Solution();
    int arr[] = {2, 3, 1, 3, 0};
    size_t count = sizeof(arr)/sizeof(int);
    vector<int> nums(arr, arr + count);
    s->containsDuplicate(nums) ? cout << "True\n" : cout << "False\n";
    delete s;
    return 0;
}
