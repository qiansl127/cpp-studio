/*
* # 41
* First Missing Positive
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size(nums.size());
        for (int i = 0; i < size; i++) {
            if (nums[i] != i + 1 && nums[i] > 0 && nums[i] <= size && nums[nums[i]-1] != nums[i]) {
                swap(nums[nums[i]-1], nums[i]);
                i--;
            }
        }
        for (int i = 0; i < size; i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return size + 1;
    }
};

int main() {
    Solution *s = new Solution();
    int array[] = {3, 4, -1, 1};
    vector<int> ivec(array, array + sizeof(array)/sizeof(int));
    cout << s->firstMissingPositive(ivec) << endl;
    delete s;
    return 0;
}
