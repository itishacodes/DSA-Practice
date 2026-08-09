#include <vector>
#include <algorithm>
#include <cstring>

class Solution {
private:
    int memo[101][201];
    int suffixSum[101];
    int n;

    int solve(int i, int M) {
        // Base case: Beyond the array
        if (i >= n) return 0;

        // Base case: If we can take all remaining piles, take them all
        if (i + 2 * M >= n) return suffixSum[i];

        // Check memoization table
        if (memo[i][M] != -1) return memo[i][M];

        int maxStones = 0;

        // Try taking X piles (1 <= X <= 2M)
        for (int X = 1; X <= 2 * M; ++X) {
            int nextM = std::max(M, X);
            int opponentStones = solve(i + X, nextM);
            
            // Total stones gained by taking X piles
            int currentStones = suffixSum[i] - opponentStones;
            maxStones = std::max(maxStones, currentStones);
        }

        return memo[i][M] = maxStones;
    }

public:
    int stoneGameII(std::vector<int>& piles) {
        n = piles.size();
        std::memset(memo, -1, sizeof(memo));

        // Precompute suffix sums
        suffixSum[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        return solve(0, 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna