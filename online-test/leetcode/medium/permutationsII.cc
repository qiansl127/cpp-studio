/*
* # 47
* Permutations II
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector< vector<int> > permuteUnique(vector<int>& nums) {
        vector< vector<int> > result;
        permuteUnique(nums, 0, result);
        return result;
    }
    void permuteUnique(vector<int>& nums, int start, vector< vector<int> >& result) {
        if(start == nums.size()) result.push_back(nums);

        for(int i = start; i < nums.size(); ++i) {
            if (containsDuplicate(nums, start, i)) {
                swap(nums[i], nums[start]);
                permuteUnique(nums, start + 1, result);
                swap(nums[i], nums[start]);
            }
        }
    }
    bool containsDuplicate(vector<int>& nums, int start, int end) {
        for (int i = start; i < end; ++i) {
            if (nums[i] == nums[end]) return false;
        }
        return true;
    }
};

int main() {
    Solution *s = new Solution();
    int array[] = {1, 2, 3, 1};
    vector<int> ivec(array, array + sizeof(array)/sizeof(int));
    vector< vector<int> > res = s->permuteUnique(ivec);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    delete s;
    return 0;
}
