class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int left = 1;

        if (n==0) return 0;

        for(int i=1; i<n; i++) {
            if (nums[i]!= nums[i-1]) {
                nums[left] = nums[i];
                left++;
            }
        }
        return left;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna