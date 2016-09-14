/*
* # 3
* Longest Substring Without Repeating Characters
*/

#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maximum = 0, start = 0;
        map<char, int> imap;
        
        for ( int i = 0; i < s.size(); i++ ) {
            map<char, int>::iterator iter = imap.find(s[i]);
            if ( iter != imap.end() ) {
                if (iter->second >= start) {
                    start = iter->second + 1;
                } else {
                    maximum = max(maximum, i - start + 1);
                }
                iter->second = i;
            } else {
                imap.insert(pair<char, int>(s[i], i));
                maximum = max(maximum, i - start + 1);
            }
        }
        
        return maximum;
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->lengthOfLongestSubstring("abcabca") << endl;
    delete s;
    return 0;
}
