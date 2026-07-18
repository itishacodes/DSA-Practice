#include <vector>
#include <algorithm>
#include <numeric> // Required for std::gcd

class Solution {
public:
    int findGCD(std::vector<int>& nums) {
        // Find the minimum and maximum elements in the array
        auto [minIt, maxIt] = std::minmax_element(nums.begin(), nums.end());
        
        int minNum = *minIt;
        int maxNum = *maxIt;
        
        // Return the GCD of the min and max
        return std::gcd(minNum, maxNum);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna