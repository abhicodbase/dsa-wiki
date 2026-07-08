/*
 * LeetCode #1025 — Divisor Game (Optimal Math Approach)
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
class Solution {
public:
    bool divisorGame(int n) {
        // Alice wins if and only if n is even.
        // If n is even, Alice can choose x = 1, leaving Bob with an odd number.
        // Odd numbers only have odd divisors, so subtracting any divisor from it
        // leaves Bob with an even number, passing the even number advantage back to Alice.
        // Alice eventually forces Bob into a losing state (n = 1).
        if (n % 2 == 0) {
            return true;
        }
        return false;
    }
};
