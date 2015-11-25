/*
* # 39
* Combination Sum
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector< vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector< vector<int> > allSolution;
        vector<int> solution;
        
        sort(candidates.begin(), candidates.end());
        findCombSum(candidates, 0, target, solution, allSolution);
        
        return allSolution;
    }
    void findCombSum(vector<int>& candidates, int start, int target, vector<int>& solution, vector< vector<int> >& allSolution) {
        if (target == 0) {
            allSolution.push_back(solution);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i-1]) continue;
            if (candidates[i] <= target) {
                solution.push_back(candidates[i]);
                findCombSum(candidates, i, target - candidates[i], solution, allSolution);
                solution.pop_back();
            }
        }
    }
};

int main() {
    Solution *s = new Solution();

    vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(3);

    vector< vector<int> > res = s->combinationSum(candidates, 9);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    delete s;
    return 0;
}
