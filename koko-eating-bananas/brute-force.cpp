#include <vector>

using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int n = piles.size();
    long long int totalBanana = 0;
    
    // Calculate the total number of bananas across all piles
    for (int i = 0; i < n; i++) {
      totalBanana += piles[i];
    }
    
    // Calculate the theoretical minimum possible speed.
    // Even without the one-pile-per-hour restriction, Koko would need to eat 
    // at least ceil(totalBanana / h) bananas per hour to finish on time.
    // This gives us an optimized starting point for our brute force search.
    int init = totalBanana / h;
    if (totalBanana % h != 0) {
      init++;
    }
    
    // Ensure the starting speed is at least 1 to prevent division by zero
    // (Only matters for edge cases where totalBanana == 0, though problem constraints usually guarantee >= 1)
    if (init == 0) {
      init = 1;
    }
    
    // Brute force: linearly check every possible speed starting from 'init'.
    // The upper bound is totalBanana, which is a safe (though loose) maximum possible speed.
    // (A tighter bound would be the maximum pile size).
    for (int i = init; i <= totalBanana; i++) {
      int count = 0; // Tracks the total hours taken at speed 'i'
      
      // Calculate how many hours it takes to eat all piles at the current speed 'i'
      for (int j = 0; j < n; j++) {
        int val = piles[j] / i; // Base hours for this pile
        // If there are leftover bananas in the pile, it takes one additional hour
        if (piles[j] % i != 0) {
          val++;
        }
        count += val;
        
        // Optimization: early exit if the current speed already takes more than 'h' hours
        if (count > h)
          break;
      }
      
      // If we successfully finished all piles within 'h' hours,
      // 'i' is the minimum valid speed since we are checking speeds in increasing order.
      if (count <= h)
        return i;
    }
    
    // Fallback return, shouldn't be reached given valid problem constraints
    return 0;
  }
};