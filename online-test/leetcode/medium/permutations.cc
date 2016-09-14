/*
* # 46
* Permutations
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector< vector<int> > permute(vector<int>& nums) {
        vector< vector<int> > result;
        permute(nums, 0, result);
        return result;
    }
    void permute(vector<int>& nums, int start, vector< vector<int> >& result) {
        if(start == nums.size()) result.push_back(nums);
        for(int i = start; i < nums.size(); ++i) {
            swap(nums[i], nums[start]);
            permute(nums, start + 1, result);
            swap(nums[i], nums[start]);
        }
    }
};

int main() {
    Solution *s = new Solution();
    int array[] = {1, 2, 3};
    vector<int> ivec(array, array + sizeof(array)/sizeof(int));
    vector< vector<int> > res = s->permute(ivec);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    delete s;
    return 0;
}
