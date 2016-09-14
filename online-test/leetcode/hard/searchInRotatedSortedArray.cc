/*
* # 33
* Search In Rotated Sorted Array
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l(0), r(nums.size()-1), n(0);
        while (l <= r) {
            n = (l + r)/2;
            if (nums[n] == target) return n;
            if (nums[n] >= nums[l]) {
                (nums[l] <= target && target < nums[n])? r = n - 1 : l = n + 1;
            } else {
                (nums[n] < target && target <= nums[r])? l = n + 1 : r = n - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution *s = new Solution();

    int arr[] = {1, 3, 5};
    vector<int> ivec(arr, arr + sizeof(arr)/sizeof(int));
    cout << s->search(ivec, 1) << endl;

    delete s;
    return 0;
}
