#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> findMissingElements(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<int> ans;

        for (int i = 0; i < (int)nums.size() - 1; ++i) {
            // Fill all values strictly between nums[i] and nums[i+1]
            for (int val = nums[i] + 1; val < nums[i + 1]; ++val) {
                ans.push_back(val);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna