/*
 * LeetCode #40 — Combination Sum II
 * https://leetcode.com/problems/combination-sum-ii/
 *
 * APPROACH: Backtracking with Sort + Sibling-Level Duplicate Skip
 * ──────────────────────────────────────────────────────────────────
 * Sort the candidates first so that duplicates are adjacent and all
 * values larger than the remaining target can be detected early with
 * a simple break.  We then explore every candidate via a recursive
 * backtrack, always advancing the start index by 1 so each element
 * is used at most once per combination.
 *
 * Key insight — the duplicate-skip guard:
 *   if (i > start && candidates[i] == candidates[i-1]) continue;
 * This skips re-using the same value at the SAME recursive level
 * (siblings), while still allowing that same value to be used at a
 * DEEPER level (children).  Without sorting, this identity check
 * would be unreliable.
 *
 * TIME  : O(2^N)  — worst case every element either in or out; pruning
 *                   makes the practical bound much tighter
 * SPACE : O(N)    — recursion depth bounded by target / min-candidate,
 *                   at most N frames; current path vector also O(N)
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
     * backtracking — explores all combinations starting from index `start`
     *   start     : lowest index we are still allowed to pick from
     *   v         : the combination being built (passed by reference)
     *   remaining : how much of the target is still left to fill
     *   candidates: sorted input array
     *   result    : accumulates every valid complete combination
     */
    void backtracking(int start, vector<int>& v, int remaining,
                      vector<int>& candidates, vector<vector<int>>& result) {

        // Base case: remaining budget is exactly 0 — combination is complete
        if (remaining == 0) {
            result.push_back(v);
            return;
        }

        for (int i = start; i < (int)candidates.size(); i++) {

            // Duplicate-skip at the same recursion level (sibling pruning):
            // If this value equals the previous one AND we haven't moved the
            // start pointer (i > start), we would produce an identical subtree
            // to the one already explored — skip it to avoid duplicate results.
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            // Early termination: array is sorted, so all further candidates
            // are also >= candidates[i] and will also exceed the budget
            if (candidates[i] > remaining) break;

            // Choose candidates[i]
            v.push_back(candidates[i]);

            // Recurse with i+1 (not i) — each element may only be used once
            backtracking(i + 1, v, remaining - candidates[i], candidates, result);

            // Un-choose: restore state for the next sibling branch
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> result;

        // Sort is mandatory: enables the duplicate-skip guard and the
        // early-break optimisation inside the backtracking loop
        sort(candidates.begin(), candidates.end());

        backtracking(0, v, target, candidates, result);
        return result;
    }
};

/*
 * ALTERNATIVE: Bitmask / Iterative Enumeration
 * ─────────────────────────────────────────────
 * For each of the 2^N subsets (represented as a bitmask), compute the
 * sum and collect subsets that hit the target, then deduplicate with a set.
 *
 *   set<vector<int>> seen;
 *   for (int mask = 0; mask < (1 << n); mask++) {
 *       vector<int> combo;
 *       int sum = 0;
 *       for (int j = 0; j < n; j++)
 *           if (mask & (1 << j)) { combo.push_back(candidates[j]); sum += candidates[j]; }
 *       if (sum == target) { sort(combo.begin(), combo.end()); seen.insert(combo); }
 *   }
 *
 * Trade-off: O(2^N · N) time and O(2^N) space — strictly worse than the
 * backtracking approach; mainly useful as a brute-force correctness check.
 *
 * EXTENSION — Unlimited use of each element (LC #39 Combination Sum):
 * Change `backtracking(i+1, …)` to `backtracking(i, …)` so the same
 * index can be revisited, and drop the duplicate-skip guard (no dups in #39).
 */
