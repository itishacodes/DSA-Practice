#include <vector>
#include <bit>

class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        int n = nums.size();
        
        // Base cases for small values of n
        if (n < 3) {
            return n;
        }
        
        // std::__lg(n) returns the index of the highest set bit (0-indexed).
        // Adding 1 gives the bit length of n.
        int bit_length = std::__lg(n) + 1;
        
        // Return 2^(bit_length)
        return 1 << bit_length;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna