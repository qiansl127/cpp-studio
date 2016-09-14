/*
* # 42
* Trapping Rain Water
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        const int size(height.size());
        if (size <= 2) return 0;
        int *maxLeft = new int[size], *maxRight = new int[size];
        maxLeft[0] = 0;
        int max(height[0]);
        for (int i = 1; i < size - 1; i++) {
            maxLeft[i] = max;
            if (max < height[i]) max = height[i];
        }
        
        maxRight[size-1] = 0;
        max = height[size-1];
        int cur(0), total(0);
        for (int i = size - 2; i > 0; i--) {
            maxRight[i] = max;
            if (max < height[i]) max = height[i];
            cur = min(maxLeft[i], maxRight[i]) - height[i];
            if (cur > 0) total += cur;
        }
        
        delete [] maxLeft;
        delete [] maxRight;
        return total;
    }
};

int main() {
    Solution *s = new Solution();
    int array[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> ivec(array, array + sizeof(array)/sizeof(int));
    cout << s->trap(ivec) << endl;
    delete s;
    return 0;
}
