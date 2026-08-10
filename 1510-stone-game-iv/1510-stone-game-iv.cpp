#include <vector>

class Solution {
public:
    bool winnerSquareGame(int n) {
        // dp[i] indicates whether the first player to move with i stones wins
        std::vector<bool> dp(n + 1, false);

        for (int i = 1; i <= n; ++i) {
            // Try removing every possible non-zero square number k*k <= i
            for (int k = 1; k * k <= i; ++k) {
                if (!dp[i - k * k]) {
                    dp[i] = true; // Found a winning move
                    break;
                }
            }
        }

        return dp[n];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna