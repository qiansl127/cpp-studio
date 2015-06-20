/*
* # 223
* Rectangle Area
*/

#include<iostream>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (A > E) return computeArea(E, F, G, H, A, B, C, D);
        int area = (C - A) * (D - B) + (G - E) * (H - F);
        if (E > C || F > D || B > H) return area;
        int xLength, yLength = 0;
        xLength = (G > C) ? (C - E) : (G - E);
        if (H < D) {
            yLength = (F > B) ? (H - F) : (H - B); 
        } else {
            yLength = (F > B) ? (D - F) : (D - B);
        }
        return area - xLength * yLength;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    delete s;
    return 0;
}
