// LeetCode 394 — Decode String
// Approach: Two-stack simulation (count stack + string stack)
//
// The key challenge: brackets nest, so we need to remember both the
// repeat count AND the string built so far before we entered each '['.
// Two parallel stacks let us restore that state on every ']'.
//
// State machine per character:
//   digit   → accumulate multi-digit number into `num`
//   '['     → freeze current (num, curr) on stacks; reset both
//   ']'     → pop count+prev, repeat curr count times, prepend prev
//   letter  → append to curr
//
// Example trace for "3[a2[bc]]":
//   char  num  curr    countStack  stringStack
//   '3'   3    ""      []          []
//   '['   0    ""      [3]         [""]
//   'a'   0    "a"     [3]         [""]
//   '2'   2    "a"     [3]         [""]
//   '['   0    ""      [3,2]       ["","a"]
//   'b'   0    "b"     [3,2]       ["","a"]
//   'c'   0    "bc"    [3,2]       ["","a"]
//   ']'   —    "a"+"bcbc"="abcbc"  [3]  [""]
//   ']'   —    ""+"abcbcabcbcabcbc" = result
//
// Time:  O(max_k × n) where max_k is the largest repeat count
//        (each char may be written up to max_k times)
// Space: O(n) — stack depth proportional to nesting level

class Solution {
public:
    string decodeString(string s) {
        stack<int>    countStack;   // saved repeat counts
        stack<string> stringStack;  // saved string prefixes

        string curr = "";   // string being built in current scope
        int    num  = 0;    // repeat count being parsed

        for (char ch : s) {

            if (isdigit(ch)) {
                // Multi-digit support: "12[a]" → num = 1*10+2 = 12
                num = num * 10 + (ch - '0');
            }
            else if (ch == '[') {
                // Entering a new nesting level — freeze current state
                countStack.push(num);
                stringStack.push(curr);
                num  = 0;
                curr = "";
            }
            else if (ch == ']') {
                // Leaving a nesting level — expand and merge
                int    cnt  = countStack.top();  countStack.pop();
                string prev = stringStack.top(); stringStack.pop();

                string expanded = "";
                for (int i = 0; i < cnt; i++)
                    expanded += curr;

                curr = prev + expanded;   // restore outer prefix + expansion
            }
            else {
                // Regular letter — append to current scope
                curr += ch;
            }
        }

        return curr;
    }
};
