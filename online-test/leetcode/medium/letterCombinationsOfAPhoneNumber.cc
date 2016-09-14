/*
* # 17
* Letter Combinations of a Phone Number
*/

#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
private:
    static char letters[8][4]; 
public:
    char* getChars(char num) {
        if (num >= '2' && num <= '9') {
            return letters[atoi(&num) - 2];
        } else {
            return NULL;
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        for (int i = 0; i < digits.size(); i++) {
            result = addLetter(result, digits[i]);
        }
        return result;

    }
    vector<string> addLetter(vector<string> origin, char num) {
        vector<string> result;
        char* chars = getChars(num);
        if (chars == NULL) return result;
        int count = 3;
        if (num == '7' || num == '9') count = 4;
        if (origin.size() == 0) {
            for (int j = 0; j < count; j++) result.push_back(string(&chars[j], 1));
        } else {
            for (int i = 0; i < origin.size(); i++) {
                for (int j = 0; j < count; j++) {
                    result.push_back(origin[i] + chars[j]);
                }
            }
        }
        return result;
    }
};
char Solution::letters[][4] = {
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'},
    {'j', 'k', 'l'},
    {'m', 'n', 'o'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'},
    {'w', 'x', 'y', 'z'}
};
int main() {
    Solution *s = new Solution();
    vector<string> result = s->letterCombinations("232");
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
    cout << endl;
    delete s;
    return 0;
}
