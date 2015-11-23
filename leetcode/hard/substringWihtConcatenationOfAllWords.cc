/*
* # 30
* Substring with Concatenation of All Words 
*/

#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = words.size();
        int n = words[0].size();
        map<string, int> wmap;
        for (int i = 0; i < words.size(); i++) {
            map<string, int>::iterator wter = wmap.find(words[i]);
            if (wter == wmap.end()) {
                wmap.insert(pair<string, int>(words[i], 1));
            } else {
                wter->second++;
            }
        }

        vector<int> res;
        for (int i = 0; i < s.size() - m*n + 1; i++) {
            string subs = s.substr(i, m*n);
            map<string, int> imap(wmap);
            for (int j = 0; j < subs.size(); j += n) {
                map<string, int>::iterator iter = imap.find(subs.substr(j, n));
                if (iter != imap.end()) {
                    iter->second--;
                    if (iter->second == 0) imap.erase(iter);
                } else {
                    break;
                }
            }
            if (imap.empty()) res.push_back(i);
        }

        return res;
    }
};

int main() {
    Solution *s = new Solution();
    vector<string> words;
    words.push_back("foo");
    words.push_back("bar");

    vector<int> res = s->findSubstring("barfoothefoobarman", words);
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout << endl;

    delete s;
    return 0;
}
