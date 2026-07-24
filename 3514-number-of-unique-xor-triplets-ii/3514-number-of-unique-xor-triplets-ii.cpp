#include <vector>
#include <algorithm>

class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        int n = nums.size();

        // Find max element to determine the upper bound for XOR values
        int maxVal = 0;
        for (int num : nums) {
            maxVal = std::max(maxVal, num);
        }

        // T will be the next power of 2 strictly greater than maxVal
        int T = 1;
        while (T <= maxVal) {
            T <<= 1;
        }

        // s1[x] will be true if 'x' can be formed as a pair XOR (nums[i] ^ nums[j])
        std::vector<bool> s1(T, false);
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                s1[nums[i] ^ nums[j]] = true;
            }
        }

        // s2[x] will be true if 'x' can be formed as a triplet XOR
        std::vector<bool> s2(T, false);
        for (int x = 0; x < T; ++x) {
            if (s1[x]) {
                for (int num : nums) {
                    s2[x ^ num] = true;
                }
            }
        }

        // Count all unique XOR triplet values
        int uniqueCount = 0;
        for (int x = 0; x < T; ++x) {
            if (s2[x]) {
                uniqueCount++;
            }
        }

        return uniqueCount;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna