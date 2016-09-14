/*
* # 6
* ZigZag Conversion
*/

#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string res[numRows];
        int i = 0, j, gap = numRows-2;
        while (i < s.size()) {
            for (j = 0; i < s.size() && j < numRows; ++j, ++i) res[j] += s[i];
            for (j = gap; i < s.size() && j > 0; --j, ++i) res[j] += s[i];
        }
        string str = "";
        for (i = 0; i < numRows; ++i)
            str += res[i];
        return str;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->convert("PAYPALISHIRING", 3) << endl;
    cout << s->convert("ABC", 3) << endl;
    cout << s->convert("ABCDE", 4) << endl;
    delete s;
    return 0;
}
