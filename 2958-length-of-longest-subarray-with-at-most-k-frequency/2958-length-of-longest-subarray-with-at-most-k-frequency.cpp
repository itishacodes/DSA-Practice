#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            freq[nums[right]]++;

            // Shrink the window until the frequency of nums[right] is <= k
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna