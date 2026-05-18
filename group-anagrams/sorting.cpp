#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    // Map to group anagrams. 
    // Key: Canonical sorted string (e.g., "aet")
    // Value: Vector of original strings (e.g., ["eat", "tea", "ate"])
    unordered_map<string, vector<string>> result;

    for (const auto &str : strs) {
      string sorted_str = str; // Make a copy of the original string
      
      // Sort the copied string to form the canonical anagram key
      sort(sorted_str.begin(), sorted_str.end());
      
      // Append the original string to the corresponding anagram group
      result[sorted_str].push_back(str); // ✅ Correct syntax
    }

    vector<vector<string>> answer;
    // Collect all the grouped anagrams into the final answer array
    for (auto &pair : result) {
      answer.push_back(pair.second);
    }
    
    return answer;
  }
};