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
        multimap<int, int> imap;
        for (int i = 0; i < nums.size(); i++) {
            imap.insert(pair<int, int>(nums[i], i));
        }
        for (int i = 0; i < nums.size(); i++) {
            int val1 = nums[i];
            int val2 = target - nums[i];
            multimap<int, int>::iterator it1 = imap.find(val1);
            imap.erase(it1);
            multimap<int, int>::iterator it2 = imap.find(val2);
            if (it2 != imap.end() ) {
                vector<int> res;
                res.push_back(i + 1);
                res.push_back(it2->second + 1);
                return res;
            }
        }
        return vector<int>(0, 2);
    }
};

int main() {
    Solution *s = new Solution();
    int arr[] = {2, 7, 11, 2};
    vector<int> inums(arr, arr + sizeof(arr)/sizeof(int));
    vector<int> res = s->twoSum(inums, 4);
    cout << res[0] << " " << res[1] << endl;
    delete s;
    return 0;
}
