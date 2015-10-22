/*
* # 18
* 4Sum
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector< vector<int> > fourSum(vector<int>& nums, int target) {
        vector< vector<int> > res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int start = j + 1, end = nums.size() - 1; start < end; ) {
                    int current = nums[i] + nums[j] + nums[start] + nums[end];
                    if (current == target) {
                        vector<int> ivec;
                        ivec.push_back(nums[i]);
                        ivec.push_back(nums[j]);
                        ivec.push_back(nums[start]);
                        ivec.push_back(nums[end]);
                        res.push_back(ivec);
                        start++;
                        while (nums[start] == nums[start-1]) start++;
                        end--;
                        while (nums[end] == nums[end+1]) end--;
                    } else if (current < target) {
                        start++;
                    } else {
                        end--;
                    }
                }
                while (nums[j] == nums[j+1]) j++;
            }
            while (nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};

int main() {
    Solution *s = new Solution();
    int array[] = {-1, 0, 1, 2, 0, -2};
    vector<int> v(array, array + sizeof(array)/sizeof(int));
    vector< vector<int> > res = s->fourSum(v, 0);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
             cout << res[i][j] << " ";
        }
        cout << endl;
    }
    delete s;
    return 0;
}
