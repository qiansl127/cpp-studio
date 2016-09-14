/*
* # 35
* Search Insert Position
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l(0), r(nums.size()-1), m(0);
        while (l <= r) {
            m = (l + r)/2;
            if (nums[m] == target) return m;
            if (nums[m] < target) {
                if (l == r) return m + 1; 
                l = m + 1;
            } else {
                if (l == r) return m;
                r = m - 1;
            }
        }
    }
};

int main() {
    Solution *s = new Solution();

    int arr[] = {1, 3, 5};
    vector<int> ivec(arr, arr + sizeof(arr)/sizeof(int));
    cout << s->searchInsert(ivec, 0) << endl;

    delete s;
    return 0;
}
