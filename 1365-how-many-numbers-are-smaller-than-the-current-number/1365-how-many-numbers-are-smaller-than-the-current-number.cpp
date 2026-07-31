#include <vector>

class Solution {
public:
    std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
        // Frequency array for numbers from 0 to 100
        std::vector<int> count(101, 0);
        
        for (int num : nums) {
            count[num]++;
        }
        
        // Compute running totals (prefix sum)
        // count[i] will store the cumulative count of numbers <= i
        for (int i = 1; i <= 100; ++i) {
            count[i] += count[i - 1];
        }
        
        std::vector<int> result(nums.size());
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                result[i] = 0; // No non-negative number is smaller than 0
            } else {
                result[i] = count[nums[i] - 1]; // Count of elements strictly smaller than nums[i]
            }
        }
        
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna