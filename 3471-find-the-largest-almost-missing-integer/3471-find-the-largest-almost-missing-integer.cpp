#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        // Case 1: k == 1 -> Find max element with total frequency == 1
        if (k == 1) {
            int ans = -1;
            for (auto& [val, count] : freq) {
                if (count == 1) {
                    ans = std::max(ans, val);
                }
            }
            return ans;
        }

        // Case 2: k == n -> Entire array is the only subarray of size k
        if (k == n) {
            int maxVal = -1;
            for (int x : nums) {
                maxVal = std::max(maxVal, x);
            }
            return maxVal;
        }

        // Case 3: 1 < k < n -> Only nums[0] or nums[n-1] can appear in 1 subarray
        int ans = -1;
        if (freq[nums[0]] == 1) {
            ans = std::max(ans, nums[0]);
        }
        if (freq[nums[n - 1]] == 1) {
            ans = std::max(ans, nums[n - 1]);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna