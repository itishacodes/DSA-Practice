#include <vector>
#include <algorithm>

class Solution {
public:
    bool predictTheWinner(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp = nums; // Base case length 1

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i] = std::max(nums[i] - dp[i + 1], nums[j] - dp[i]);
            }
        }

        return dp[0] >= 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna