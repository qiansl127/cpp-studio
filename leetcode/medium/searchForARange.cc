/*
* # 34
* Search for a Range
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l(0), r(nums.size() - 1), m(0);
        vector<int> res;
        while (l <= r) {
            m = (l + r) / 2;
            if (nums[m] < target) {
                l = m + 1;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                int m1(m-1), m2(m+1);
                while (m1 >= l && nums[m1] == target) m1--;
                while (m2 <= r && nums[m2] == target) m2++;
                res.push_back(m1 + 1);
                res.push_back(m2 - 1);
                return res;
            }
        }
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
};

int main() {
    Solution *s = new Solution();

    int arr[] = {1, 3, 3, 5};
    vector<int> ivec(arr, arr + sizeof(arr)/sizeof(int));
    vector<int> res = s->searchRange(ivec, 3);
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout << endl;

    delete s;
    return 0;
}
