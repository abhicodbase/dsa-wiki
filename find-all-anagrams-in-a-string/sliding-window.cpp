#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> anagramS(26,0);
        vector<int> anagramP(26,0);
        vector<int> result;
        if(s.length() < p.length()) return result;
        int len = p.length(), idx;
        for(int i=0;i<len;i++) anagramP[p[i]-'a']++;
        for(int i=0;i<len;i++) anagramS[s[i]-'a']++;
        idx = len-1;
        while(idx < s.length()) {
            if(idx == len-1) {
                if(anagramS==anagramP) result.push_back(idx-len+1);
                idx++;
                continue;
            } 
            int outWindow = idx - len;
            anagramS[s[outWindow]-'a']--;
            anagramS[s[idx]-'a']++;
            if(anagramS==anagramP) {
                result.push_back(idx-len+1);
            }
            idx++;
        }
        return result;
    }
};
