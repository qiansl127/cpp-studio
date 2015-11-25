/*
* # 36
* Valid Sukodu
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector< vector<char> >& board) {
        // check rows
        for (int i = 0; i < 9; i++) {
            vector<bool> used(9, false);
            for (int j = 0; j < 9; j++) {
                if(!isdigit(board[i][j])) continue;
                int k = board[i][j] - '0';
                if(k == 0 || used[k-1]) return false;
                used[k-1] = true;
            }
        }
        
        // check columns
        for (int j = 0; j < 9; j++) {
            vector<bool> used(9, false);
            for (int i = 0; i < 9; i++) {
                if(!isdigit(board[i][j])) continue;
                int k = board[i][j] - '0';
                if(k == 0 || used[k-1]) return false;
                used[k-1] = true;
            }
        }
        
        // check small squares
        for (int k = 0; k < 9; k += 3) {
            for (int l = 0; l < 9; l += 3) {
                vector<bool> used(9, false);
                for (int i = k; i < k + 3; i++) {
                    for (int j = l; j < l + 3; j++) {
                        if(!isdigit(board[i][j])) continue;
                        int k = board[i][j] - '0';
                        if(k == 0 || used[k-1]) return false;
                        used[k-1] = true;
                    }
                }
            }
        }
        
        return true;
    }
};

int main() {
    Solution *s = new Solution();

    char array[] = {'1', '2', '3', '.', '.', '.', '.' , '.', '9'};
    vector<char> ivec(array, array + sizeof(array)/sizeof(int));
    vector< vector<char> > board;
    for (int i = 0; i < 9; i++) board.push_back(ivec);

    cout << s->isValidSudoku(board) << endl;

    delete s;
    return 0;
}
