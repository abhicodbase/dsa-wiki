#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    // Create a dictionary from the wordList for O(1) lookup and deletion
    unordered_set<string> dict(wordList.begin(), wordList.end());
    
    // If the target word is not in the dictionary, no sequence exists
    if (dict.find(endWord) == dict.end())
      return 0;

    // Queue stores pairs of (current_word, current_steps)
    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    while (!q.empty()) {
      string word = q.front().first;
      int steps = q.front().second;
      q.pop();

      // If we've reached the target word, return the number of steps
      if (word == endWord)
        return steps;

      // Try changing every single character of the current word
      for (int i = 0; i < word.length(); ++i) {
        char original = word[i];
        
        // Replace the character with every letter from 'a' to 'z'
        for (char c = 'a'; c <= 'z'; ++c) {
          if (c == original)
            continue;
            
          word[i] = c;
          
          // If the new word is valid (exists in the dictionary)
          if (dict.count(word)) {
            // Push the new word to the queue and increment the step count
            q.push({word, steps + 1});
            
            // Erase the word from dictionary to prevent visiting it again (cycle prevention)
            dict.erase(word);
          }
        }
        
        // Restore the original character to try changing the next position
        word[i] = original;
      }
    }

    // If queue is empty and we haven't reached the endWord, return 0
    return 0;
  }
};

int main() {
  Solution sol;
  string beginWord = "hit";
  string endWord = "cog";
  vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
  cout << "Input: hit -> cog | Output: "
       << sol.ladderLength(beginWord, endWord, wordList) << endl;

  vector<string> wordList2 = {"hot", "dot", "dog", "lot", "log"};
  cout << "Input: hit -> cog (not in list) | Output: "
       << sol.ladderLength(beginWord, endWord, wordList2) << endl;

  return 0;
}
