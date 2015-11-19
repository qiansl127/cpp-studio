/*
* # 27
* Remove Element
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator iter = nums.begin();
        while (iter != nums.end()) {
            if (val == *iter) {
                nums.erase(iter);
                continue;
            }
            iter++;
        }
        return nums.size();
    }
};

int main() {
    Solution *s = new Solution();

    int arr[] = {1, 3, 1, 2, 4, 3, 4};
    vector<int> nvec(arr, arr + sizeof(arr)/sizeof(int));
    cout << "Size: " << s->removeElement(nvec, 4) << endl;
    for (int i = 0; i < nvec.size(); i++) cout << nvec[i] << " ";
    cout << endl;

    delete s;
    return 0;
}
