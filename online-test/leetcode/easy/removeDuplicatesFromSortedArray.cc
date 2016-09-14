/*
* # 26
* Remove Duplicates From Sorted Array
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return size;
        int end(0);
        for (int i = 1; i < size; i++) {
            if (nums[i] != nums[end]) {
                end++;
                if (i != end) nums[end] = nums[i];
            }
        }
        nums.erase(nums.begin() + end + 1, nums.end());
        return end + 1;
    }
};

int main() {
    Solution *s = new Solution();

    int arr[] = {1, 1, 1, 2, 3, 3, 4};
    vector<int> nvec(arr, arr + sizeof(arr)/sizeof(int));
    cout << "Size: " << s->removeDuplicates(nvec) << endl;
    for (int i = 0; i < nvec.size(); i++) cout << nvec[i] << " ";
    cout << endl;

    delete s;
    return 0;
}
