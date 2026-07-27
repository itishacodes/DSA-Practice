#include <vector>
#include <algorithm>
class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        int mul = (nums[n-1]-1)*(nums[n-2]-1);
        return mul;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna