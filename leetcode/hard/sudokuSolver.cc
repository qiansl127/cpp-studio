/*
* # 37
* Sukodu Solver
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector< vector<char> >& board) {
        solSudoku(board, 0, 0);
    }
    
    bool solSudoku(vector< vector<char> >& board, int irow, int icol) {
        if (irow == 9) return true;
        
        int irow1(irow), icol1(icol);
        if (icol == 8) {
            irow1++;
            icol1 = 0;
        } else {
            icol1++;
        }
        
        if (board[irow][icol] != '.') {
            if (!isValid(board, irow, icol)) return false;
            return solSudoku(board, irow1, icol1);
        }
        
        for (int i = 0; i < 9; i++) {
            board[irow][icol] = i + '1';
            if (isValid(board, irow, icol) && solSudoku(board, irow1, icol1)) return true;
        }
        
        board[irow][icol] = '.';
        return false;
    }
    
    bool isValid(vector< vector<char> >& board, int irow, int icol) {
        char val = board[irow][icol];
        
        for (int t = 0; t < 9; t++) {
            if (board[irow][t] == val && t != icol) return false;
            if (board[t][icol] == val && t != irow) return false;
        }
        
        int irow0(irow/3*3), icol0(icol/3*3);
        for (int i = irow0; i < irow0 + 3; i++) {
            for (int j = icol0; j < icol0 + 3; j++) {
                if (board[i][j] == val && (i != irow || j != icol)) return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution *s = new Solution();

    char array[][9] = {
        {'.', '.', '.', '.', '.', '.', '.' , '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.' , '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.' , '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.' , '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.' , '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.' , '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.' , '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.' , '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.' , '.', '.'},
    };
    vector< vector<char> > board;
    for (int i = 0; i < 9; i++) {
        vector<char> ivec(array[i], array[i] + sizeof(array[i])/sizeof(char));
        board.push_back(ivec);
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    s->solveSudoku(board);
    cout << "\nAfter filling:\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    delete s;
    return 0;
}
