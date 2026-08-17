#include <vector>
#include <algorithm>
#include <cstring>

class Solution {
private:
    int memo[501][501];
    int prefix[502];

    int solve(int i, int j) {
        // Base case: Single stone remaining, game ends
        if (i == j) return 0;

        if (memo[i][j] != -1) return memo[i][j];

        int maxScore = 0;

        // Try every possible partition index k from i to j - 1
        for (int k = i; k < j; ++k) {
            int leftSum = prefix[k + 1] - prefix[i];
            int rightSum = prefix[j + 1] - prefix[k + 1];

            if (leftSum < rightSum) {
                maxScore = std::max(maxScore, leftSum + solve(i, k));
            } else if (leftSum > rightSum) {
                maxScore = std::max(maxScore, rightSum + solve(k + 1, j));
            } else {
                // When sums are equal, Alice picks the better outcome
                int optionLeft = leftSum + solve(i, k);
                int optionRight = rightSum + solve(k + 1, j);
                maxScore = std::max({maxScore, optionLeft, optionRight});
            }
        }

        return memo[i][j] = maxScore;
    }

public:
    int stoneGameV(std::vector<int>& stoneValue) {
        int n = stoneValue.size();
        std::memset(memo, -1, sizeof(memo));

        prefix[0] = 0;
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        return solve(0, n - 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna