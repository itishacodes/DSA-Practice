#include <vector>
#include <algorithm>

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        // Step 1: Sort the vector
        std::sort(nums.begin(), nums.end());

        // Step 2: Remove duplicates
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

        int n = nums.size();

        // Step 3: Return the third maximum if it exists, otherwise the maximum
        if (n >= 3) {
            return nums[n - 3];
        } else {
            return nums[n - 1];
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna