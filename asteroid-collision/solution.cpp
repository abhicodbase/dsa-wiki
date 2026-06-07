#include <vector>
#include <stack>
#include <iostream>
using namespace std;

/**
 * @brief Simulates asteroid collisions.
 *
 * Each asteroid is represented by an integer where the sign indicates direction:
 *   positive -> moving right, negative -> moving left.
 * When two asteroids meet, the smaller (by absolute value) is destroyed; if they are
 * equal, both are destroyed. The function returns the state of the asteroids after
 * all possible collisions.
 *
 * Approach:
 *   - Use a stack to keep the surviving asteroids moving to the right.
 *   - Iterate over the input list:
 *       * If the current asteroid moves right (positive) or the stack is empty, push it.
 *       * If it moves left (negative), compare it with the top of the stack (which
 *         must be a right‑moving asteroid). Resolve the collision according to the
 *         rules, possibly popping the stack or discarding the current asteroid.
 *   - After processing, the stack contains the survivors in order. Transfer them
 *     to a vector for the result.
 *
 * Time Complexity: O(N) – each asteroid is pushed/popped at most once.
 * Space Complexity: O(N) – stack stores at most N asteroids.
 */
class Solution {
public:
    /**
     * @brief Returns the state of asteroids after all collisions.
     * @param asteroids Vector of integers representing asteroids.
     * @return Vector of remaining asteroids.
     */
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk; // holds asteroids moving to the right
        for (int cur : asteroids) {
            bool survived = true;
            // Resolve collisions while current asteroid moves left and top of stack moves right
            while (survived && !stk.empty() && stk.top() > 0 && cur < 0) {
                int top = stk.top();
                // If sizes are equal, both explode
                if (abs(top) == abs(cur)) {
                    survived = false; // current asteroid destroyed
                    stk.pop();        // top asteroid destroyed
                } else if (abs(top) > abs(cur)) {
                    // Top asteroid is larger; current asteroid destroyed
                    survived = false;
                } else { // cur is larger
                    // Top asteroid destroyed; continue checking with next stack element
                    stk.pop();
                }
            }
            if (survived) {
                stk.push(cur);
            }
        }
        // Transfer stack to vector in correct order
        vector<int> result(stk.size());
        for (int i = result.size() - 1; i >= 0; --i) {
            result[i] = stk.top();
            stk.pop();
        }
        return result;
    }
};
