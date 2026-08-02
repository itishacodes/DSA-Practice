#include <algorithm>

class Solution {
public:
    int arrayPairSum(std::vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        std::sort(nums.begin(), nums.end());
        for (int i=0; i<n-1; i=i+2) {
            sum = sum + std::min(nums[i], nums[i+1]);
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna