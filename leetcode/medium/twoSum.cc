/*
* # 1
* Two Sum
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> imap;
        for (int i = 0; i < nums.size(); i++) {
            imap.insert(pair<int, int>(nums[i], i));
        }
        for (int i = 0; i < nums.size(); i++) {
            int one = nums[i];
            int theOther = target - nums[i];
            vector<int> res;
            res.push_back(i + 1);
            if (one != theOther) {
                map<int, int>::iterator iter = imap.find(theOther);
                if (iter != imap.end()) {
                    res.push_back(iter->second + 1);
                    return res;
                }
            } else {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (theOther == nums[j]) {
                        res.push_back(j + 1);
                        return res;
                    }
                }
            }
        }
        return vector<int>(0, 2);
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> inums;
    inums.push_back(2);
    inums.push_back(7);
    inums.push_back(11);
    inums.push_back(2);
    vector<int> res = s->twoSum(inums, 4);
    cout << res[0] << " " << res[1] << endl;
    delete s;
    return 0;
}
