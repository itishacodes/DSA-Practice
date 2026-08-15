#include <vector>

class Solution {
public:
    int longestSubsequence(std::vector<int>& nums) {
        int totalXor = 0;
        bool hasNonZero = false;

        for (int x : nums) {
            totalXor ^= x;
            if (x != 0) {
                hasNonZero = true;
            }
        }

        // Case 1: All elements are 0
        if (!hasNonZero) {
            return 0;
        }

        // Case 2: Overall XOR is non-zero -> take the whole array
        if (totalXor != 0) {
            return nums.size();
        }

        // Case 3: Overall XOR is zero but contains non-zero elements -> take N - 1 elements
        return nums.size() - 1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna