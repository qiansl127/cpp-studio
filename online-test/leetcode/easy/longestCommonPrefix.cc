/*
* # 14
* Longest Common Prefix
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() < 1) return "";
        int length = 0;
        for (length = 0; ; length++) {
            char t = strs[0][length];
            int i = 0;
            for (i = 0; i < strs.size(); i++) {
                if (length >= strs[i].size() || strs[i][length] != t) {
                    break;
                }
            }
            if (i != strs.size()) {
                break;
            }
        }
        return strs[0].substr(0, length);
    }
};

int main() {
    Solution *s = new Solution();
    vector<string> ivec;
    ivec.push_back("abc");
    ivec.push_back("abdd");
    cout << s->longestCommonPrefix(ivec) << endl;
    delete s;
    return 0;
}
