#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    // Use unordered_map to store the dictionary and visited words
    unordered_map<string, bool> visited, wordDist;
    
    // Populate the wordDist map with words from the list
    for (vector<string>::iterator it = wordList.begin(); it != wordList.end(); it++) {
      wordDist[*it] = true;
    }
    
    // Queue for BFS traversal storing pairs of {current_word, current_level}
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    
    while (!q.empty()) {
      pair<string, int> p = q.front();
      q.pop();
      string str = p.first;
      int strLength = str.length();
      
      // Try replacing each character of the current word
      for (int i = 0; i < strLength; i++) {
        string tmpStr = str;
        // Replace with all possible lowercase letters from 'a' to 'z'
        for (int j = 0; j < 26; j++) {
          tmpStr[i] = 'a' + j;
          
          // Check if the modified word exists in the dictionary and hasn't been visited.
          // FIX: Use .count(tmpStr) to prevent unintentionally inserting non-existent
          // randomly generated string permutations into the wordDist map, which 
          // caused Memory Limit Exceeded / TLE.
          if (wordDist.count(tmpStr) && !visited[tmpStr]) {
            // Check if we have reached our target word
            if (tmpStr == endWord) {
              return p.second + 1;
            }
            // Push the valid dictionary word to the queue and mark it as visited
            q.push({tmpStr, p.second + 1});
            visited[tmpStr] = true;
          }
        }
      }
    }
    
    // If the queue becomes empty without reaching the end word, no path exists
    return 0;
  }
};