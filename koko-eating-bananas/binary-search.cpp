#include <algorithm> // Added for std::max
#include <vector>

using namespace std;

class Solution {
public:
  // Helper function to check if Koko can eat all bananas at a given 'speed'
  // within 'h' hours
  bool canEatBanana(vector<int> &piles, long long speed, int h) {
    long long count =
        0; // Tracks the total hours taken to eat all bananas at 'speed'

    // Iterate through each pile of bananas
    for (int j = 0; j < piles.size(); j++) {
      // Calculate hours needed for the current pile
      count += piles[j] / speed;
      // If there are leftover bananas in the pile, it takes an extra hour
      if (piles[j] % speed != 0)
        count++;

      // Optimization: if total hours exceed 'h', Koko cannot finish at this
      // speed
      if (count > h) {
        return false;
      }
    }

    // If all piles are finished within 'h' hours, this speed works
    return true;
  }

  // Main function to find the minimum eating speed
  int minEatingSpeed(vector<int> &piles, int h) {
    int mx = 0;
    long long sum = 0;
    // Find the maximum pile size. This represents the upper bound for our
    // binary search. Eating faster than the largest pile doesn't save time
    // since Koko can only eat from one pile per hour.
    for (int i = 0; i < piles.size(); i++) {
      mx = max(mx, piles[i]);
      sum += piles[i];
    }
    int init = sum / h;
    if (sum % h != 0)
      init++;

    // Initialize binary search boundaries for the eating speed.
    // Minimum possible speed is 1 (changed from 0 to prevent division by zero).
    long long low = init, high = mx, mid;

    // Perform binary search to find the minimum valid speed
    while (low < high) {
      mid = low + (high - low) / 2; // Try the middle speed

      // If Koko can finish at speed 'mid', then 'mid' could be the answer,
      // but we should check if she can eat even slower. Search the left half
      // (including 'mid').
      if (canEatBanana(piles, mid, h)) {
        high = mid;
      } else {
        // If Koko cannot finish at speed 'mid', she needs to eat faster.
        // Discard the left half and search the right half.
        low = mid + 1;
      }
    }

    // 'low' and 'high' will converge to the minimum valid eating speed
    return low;
  }
};