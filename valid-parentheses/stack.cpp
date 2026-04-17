#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  // Helper function to check if the top of the stack matches the current closing bracket
  bool isPopAllowd(char sc, char strc) {
    if (sc == '(' && strc == ')')
      return true;
    if (sc == '{' && strc == '}')
      return true;
    if (sc == '[' && strc == ']')
      return true;
    return false;
  }
  
  // Validates if the given string contains correctly nested parentheses
  bool isValid(string s) {
    stack<char> stk;
    
    // Push the first character onto the stack unconditionally
    // Note: If the string is empty, accessing s[0] can cause an out-of-bounds error.
    // It's assumed the input string `s` is non-empty. 
    // If it can be empty, a check like `if (s.empty()) return true;` is needed.
    stk.push(s[0]);
    
    // Iterate through the rest of the string
    for (int i = 1; i < s.length(); i++) {
      if (!stk.empty()) {
        char ch = stk.top(); // Get top element
        if (isPopAllowd(ch, s[i])) { // If matches the closing bracket
          stk.pop();
        } else { // Otherwise, push onto stack
          stk.push(s[i]);
        }
      } else {
        // If stack is empty, push the current character
        stk.push(s[i]);
      }
    }
    
    // If stack is completely empty, it means all the brackets were matched correctly
    return stk.empty();
  }
};