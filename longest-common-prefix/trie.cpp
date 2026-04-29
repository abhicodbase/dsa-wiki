#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Trie node structure to store characters
    class TrieNode {
    public:
        TrieNode* children[26];
        bool isWord;
        TrieNode() {
            isWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
    };

    /**
     * Inserts a string into the Trie.
     */
    void insertStringTrie(string str, TrieNode* root) {
        TrieNode* current = root;
        int len = str.length();
        for (int i = 0; i < len; i++) {
            // Create a new node if path doesn't exist
            if (current->children[str[i] - 'a'] == NULL)  {
                TrieNode* newChild = new TrieNode();
                current->children[str[i] - 'a'] = newChild;
            }
            // Move to the child node
            current = current->children[str[i] - 'a'];
        }
        // Mark the end of a word
        current->isWord = true;
    }

    /**
     * Traverses the Trie to find the longest common prefix.
     * The prefix stops when a node has more than one child or marks the end of a word.
     */
    string getCommomPrefix(TrieNode* root) {
        TrieNode* current = root;
        string prefix = "";
        while (current != NULL) {
            int count = 0, idx = -1; 
            TrieNode* next = NULL;
            
            // Count how many children the current node has
            for (int i = 0; i < 26; i++) {
                if(current->children[i] != NULL) {
                    count++;
                    idx = i;
                    next = current->children[i];
                } 
            }
            
            // Stop if: multiple children (strings diverge) OR current node is marked as word (a string ended)
            if (count != 1 || current->isWord) {
                return prefix;
            }
            
            // Append the character to the prefix
            prefix += (idx + 'a');
            current = next;
        }
        return prefix;
    }

    /**
     * Finds the longest common prefix among an array of strings using a Trie.
     */
    string longestCommonPrefix(vector<string>& strs) {
        // Edge case: Empty input array
        if (strs.empty()) return "";

        TrieNode* root = new TrieNode();
        
        // Build the Trie using all strings
        for (int i = 0; i < strs.size(); i++) {
            // If there's an empty string, the common prefix is empty
            if (strs[i].empty()) return "";
            insertStringTrie(strs[i], root);
        }
        
        // Retrieve the longest common prefix
        return getCommomPrefix(root);
    }
};