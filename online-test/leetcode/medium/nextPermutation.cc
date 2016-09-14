/*
* # 31
* Next Permutation
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size(nums.size()), i(size - 1), j(i), temp(nums[i]);
        while (i > 0) {
            i--;
            if (nums[i] >= temp) {
                temp = nums[i];
            } else {
                break;
            }
        }

        while (j > i) {
            if (nums[j] > nums[i]) {
                break;
            }
            j--;
        }

        if (i != j) {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        } else {
            i--;
        }
    
        for (int k1(i + 1), k2(size - 1); k1 < k2; k1++, k2--) {
            temp = nums[k1];
            nums[k1] = nums[k2];
            nums[k2] = temp;
        }
    }
};

int main() {
    Solution *s = new Solution();

    int array[] = {5, 4, 7, 5, 3, 2};
    vector<int> nums(array, array + sizeof(array)/sizeof(int));

    s->nextPermutation(nums);

    for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
    cout << endl;

    delete s;
    return 0;
}
