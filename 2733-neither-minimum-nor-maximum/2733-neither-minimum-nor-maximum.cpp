class Solution {
public:
    int findNonMinOrMax(std::vector<int>& nums) {
        
        // std::sort(nums.begin(), nums.end());
        // nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

        // int n = nums.size();

        // if (n<3) {
        //     return -1;
        // }
        // else return nums[1];
        
        int n = nums.size();

        if (n>=3) {
            int a = nums[0];
            int b = nums[1];
            int c = nums[2];

            return ((a+b+c) - std::max({a, b, c}) - std::min({a, b, c}));
        }
        return -1;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna