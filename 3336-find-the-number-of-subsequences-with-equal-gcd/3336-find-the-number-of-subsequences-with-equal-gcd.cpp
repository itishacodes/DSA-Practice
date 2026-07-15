#include <vector>
#include <numeric>
#include <cstring>

using namespace std;

class Solution {
    int memo[201][201][201];
    const int MOD = 1e9 + 7;

    int solve(int i, int g1, int g2, const vector<int>& nums) {
        if (i == nums.size()) {
            return (g1 > 0 && g1 == g2) ? 1 : 0;
        }
        if (memo[i][g1][g2] != -1) return memo[i][g1][g2];

        // Choice 1: Skip nums[i]
        long long res = solve(i + 1, g1, g2, nums);

        // Choice 2: Add nums[i] to the first subsequence
        int next_g1 = (g1 == 0) ? nums[i] : std::gcd(g1, nums[i]);
        res = (res + solve(i + 1, next_g1, g2, nums)) % MOD;

        // Choice 3: Add nums[i] to the second subsequence
        int next_g2 = (g2 == 0) ? nums[i] : std::gcd(g2, nums[i]);
        res = (res + solve(i + 1, g1, next_g2, nums)) % MOD;

        return memo[i][g1][g2] = (int)res;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        // memset is efficient for initializing the memoization table
        memset(memo, -1, sizeof(memo));
        return solve(0, 0, 0, nums);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna