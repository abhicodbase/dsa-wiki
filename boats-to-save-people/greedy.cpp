#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Computes the minimum number of rescue boats needed to carry all people.
     * Each boat can carry at most two people at the same time, provided the sum
     * of their weights is at most the given limit.
     * 
     * @param people The weights of the people.
     * @param limit The maximum weight limit of a single rescue boat.
     * @return The minimum number of boats required.
     */
    int numRescueBoats(vector<int>& people, int limit) {
        // Sort the weights of the people in ascending order
        sort(people.begin(), people.end());
        
        int left = 0;
        int right = people.size() - 1;
        int count = 0;
        
        // Use two pointers representing the lightest and heaviest person remaining
        while (left <= right) {
            // If the lightest and heaviest person can fit in the same boat, pair them
            if (people[left] + people[right] <= limit) {
                left++;
                right--;
            } else {
                // Otherwise, the heaviest person must take a boat alone
                right--;
            }
            
            // In either case, one boat is sent
            count++;
        }
        
        return count;
    }
};
