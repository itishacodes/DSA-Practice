#include <vector>
#include <unordered_set>

class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        int sum = nums[0];
        
        // Step 1: Calculate sum of longest sequential prefix starting from index 0
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break; // Sequential prefix breaks
            }
        }

        // Step 2: Store all numbers in a set for O(1) existence lookup
        std::unordered_set<int> present(nums.begin(), nums.end());

        // Step 3: Find smallest integer x >= sum not in nums
        int x = sum;
        while (present.count(x)) {
            x++;
        }

        return x;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna