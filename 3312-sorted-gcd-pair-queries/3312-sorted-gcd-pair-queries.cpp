#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    std::vector<int> gcdValues(std::vector<int>& nums, std::vector<long long>& queries) {
        int maxNum = 0;
        for (int num : nums) maxNum = std::max(maxNum, num);

        // Step 1: Count how many numbers are divisible by each d
        std::vector<long long> countDivisor(maxNum + 1, 0);
        for (int num : nums) {
            for (int i = 1; i * i <= num; ++i) {
                if (num % i == 0) {
                    countDivisor[i]++;
                    if (i * i != num) countDivisor[num / i]++;
                }
            }
        }

        // Step 2: Calculate pairs with exact GCD g
        std::vector<long long> countGcdPair(maxNum + 1, 0);
        for (int g = maxNum; g >= 1; --g) {
            long long v = countDivisor[g];
            countGcdPair[g] = v * (v - 1) / 2;
            for (int multiple = 2 * g; multiple <= maxNum; multiple += g) {
                countGcdPair[g] -= countGcdPair[multiple];
            }
        }

        // Step 3: Prefix sums
        std::vector<long long> prefixCount(maxNum + 1, 0);
        for (int i = 1; i <= maxNum; ++i) {
            prefixCount[i] = prefixCount[i - 1] + countGcdPair[i];
        }

        // Step 4: Answer queries using binary search
        std::vector<int> ans;
        for (long long q : queries) {
            auto it = std::upper_bound(prefixCount.begin(), prefixCount.end(), q);
            ans.push_back(std::distance(prefixCount.begin(), it));
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna