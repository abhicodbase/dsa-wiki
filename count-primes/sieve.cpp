#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        // isPrime[i] tracks whether integer i is prime.
        // Initially assume all numbers >= 2 are prime.
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        
        // Sieve of Eratosthenes
        // Outer loop runs up to sqrt(n)
        for (long long i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                // Multiples of i smaller than i*i are already marked by smaller prime factors.
                // Use long long for (i * i) to prevent 32-bit integer overflow.
                for (long long j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        // Count all remaining primes strictly less than n
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
            }
        }
        
        return count;
    }
};
