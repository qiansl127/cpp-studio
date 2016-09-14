/*
* # 45
* Jump Game II
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int start(0), end(1), count(0);
        while (end < nums.size()) {
            count++;
            int farthest(0);
            for (int j = start; j < end; j++) {
                if (j + nums[j] >= nums.size() - 1) return count;
                if (j + nums[j] > farthest) farthest = j + nums[j];
            }
            start = end;
            end = farthest + 1;
        }
        return -1;
    }
};

int main() {
    Solution *s = new Solution();
    int array[] = {2, 3, 1, 1, 4};
    vector<int> ivec(array, array + sizeof(array)/sizeof(int));
    cout << s->jump(ivec) << endl;
    delete s;
    return 0;
}
