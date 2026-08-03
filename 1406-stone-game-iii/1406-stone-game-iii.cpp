class Solution {
public:
    std::string stoneGameIII(std::vector<int>& stoneValue) {
        int n = stoneValue.size();
        int dp1 = 0, dp2 = 0, dp3 = 0; // Represents dp[i+1], dp[i+2], dp[i+3]

        for (int i = n - 1; i >= 0; --i) {
            int maxDiff = INT_MIN;
            int currentSum = 0;

            if (i < n) {
                currentSum += stoneValue[i];
                maxDiff = std::max(maxDiff, currentSum - dp1);
            }
            if (i + 1 < n) {
                currentSum += stoneValue[i + 1];
                maxDiff = std::max(maxDiff, currentSum - dp2);
            }
            if (i + 2 < n) {
                currentSum += stoneValue[i + 2];
                maxDiff = std::max(maxDiff, currentSum - dp3);
            }

            // Shift DP states for the next iteration
            dp3 = dp2;
            dp2 = dp1;
            dp1 = maxDiff;
        }

        if (dp1 > 0) return "Alice";
        if (dp1 < 0) return "Bob";
        return "Tie";
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna