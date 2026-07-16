#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long gcdSum(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> prefixGcd;
        int maxEl = -1;
        
        // Step 1: Construct prefixGcd array
        for (int i = 0; i < n; ++i) {
            maxEl = std::max(maxEl, nums[i]);
            prefixGcd.push_back(std::gcd(nums[i], maxEl));
        }
        
        // Step 2: Sort the array
        std::sort(prefixGcd.begin(), prefixGcd.end());
        
        // Step 3: Form pairs and compute sum of GCDs
        long long totalGcdSum = 0;
        int left = 0;
        int right = n - 1;
        
        while (left < right) {
            totalGcdSum += std::gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        
        return totalGcdSum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna