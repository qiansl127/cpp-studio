/*
* # 11
* Container With Most Water
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int area = 0;
        while (i != j) {
            int wd = j - i;
            int ht = 0;
            if (height[i] < height[j]) {
                ht = height[i];
                i++;
            } else {
                ht = height[j];
                j--;
            }
            if (wd * ht > area) area = wd * ht;
        }
        return area;
    }
};

int main() {
    Solution *s = new Solution();
    int arr[] = {3, 7, 1, 5};
    vector<int> ivec(arr, arr + sizeof(arr)/sizeof(int));
    cout << s->maxArea(ivec) << endl;
    delete s;
    return 0;
}
