/*
* # 40
* Combination Sum II
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector< vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector< vector<int> > allSolution;
        vector<int> solution;
        
        sort(candidates.begin(), candidates.end());
        findCombSum2(candidates, 0, target, solution, allSolution);
        
        return allSolution;
    }
    void findCombSum2(vector<int>& candidates, int start, int target, vector<int>& solution, vector< vector<int> >& allSolution) {
        if (target == 0) {
            allSolution.push_back(solution);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i-1]) continue; // equal number will be added in deeply recursion
            if (candidates[i] <= target) {
                solution.push_back(candidates[i]);
                findCombSum2(candidates, i + 1, target - candidates[i], solution, allSolution);
                solution.pop_back();
            }
        }
    }
};

int main() {
    Solution *s = new Solution();

    int array[] = {10, 1, 6, 1};
    vector<int> candidates(array, array + sizeof(array)/sizeof(int));

    vector< vector<int> > res = s->combinationSum2(candidates, 8);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    delete s;
    return 0;
}
