/*
* # 55
* Jump Game
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest(0);
        for (int i = 0; i < nums.size(); i++) {
            if (farthest < i) return false;
            if (farthest >= nums.size() - 1) return true;
            if (farthest < i + nums[i]) farthest = i + nums[i];
        }
        return true;
    }
};

int main() {
    Solution *s = new Solution();
    int array[] = {3, 2, 1, 0, 4};
    vector<int> ivec(array, array + sizeof(array)/sizeof(int));
    cout << s->canJump(ivec) << endl;
    delete s;
    return 0;
}
