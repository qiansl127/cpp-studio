/*
* # 28
* Implement strStr()
*/

#include<iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int nsize = needle.size();
        if (nsize == 0) return 0;
        // size() returns unsigned int
        if (haystack.size() < nsize) return -1; 
        for (int i = 0; i < haystack.size() - nsize + 1; i++) {
            int j(0);
            for (; j < nsize; j++) {
                if (haystack[i+j] != needle[j]) break;
            }
            if (j == nsize) return i;
        }
        return -1;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->strStr("abb", "abaaa") << endl;
    delete s;
    return 0;
}
