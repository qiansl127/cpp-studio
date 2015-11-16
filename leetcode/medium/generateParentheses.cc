/*
* # 22
* Generate Parentheses
* Depth First Search
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, "", n, n);
        return res;
    }
    void dfs(vector<string>& svec, string s, int left, int right) {
        // left and right means the number of "(" and ")" not assigned
        // add from left to right
        if (left > right) return;
        if (left == 0 && right == 0) {
            svec.push_back(s);
            return;
        }
        if (left > 0) {
            dfs(svec, s + "(", left - 1, right);
        }
        if (right > 0) {
            dfs(svec, s + ")", left, right - 1);
        }
    }
};

int main() {
    Solution *s = new Solution();
    vector<string> res = s->generateParenthesis(4);
    for (int i = 0; i < res.size(); i++) cout << res[i] << endl;
    delete s;
    return 0;
}
