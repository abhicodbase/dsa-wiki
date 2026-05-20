#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> result;
    vector<vector<string>> groupAnagram;
    for (auto it = strs.begin(); it != strs.end(); it++) {
      string str = *it;
      vector<int> anagram(26, 0);
      for (int i = 0; i < str.length(); i++) {
        anagram[str[i] - 'a']++;
      }
      string ns = "";
      for (int i = 0; i < 26; i++) {
        if (anagram[i] > 0) {
          for (int j = 0; j < anagram[i]; j++) {
            ns += (i + 'a');
          }
        }
      }
      result[ns].push_back(str);
    }
    for (auto it = result.begin(); it != result.end(); it++) {
      groupAnagram.push_back(it->second);
    }
    return groupAnagram;
  }
};