#include <vector>

class Solution {
private:
    void merge(std::vector<int>& nums, int left, int mid, int right, std::vector<int>& temp) {
        int i = left;
        int j = mid + 1;
        int k = left;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid) temp[k++] = nums[i++];
        while (j <= right) temp[k++] = nums[j++];

        for (int p = left; p <= right; p++) {
            nums[p] = temp[p];
        }
    }

    void mergeSort(std::vector<int>& nums, int left, int right, std::vector<int>& temp) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid, temp);
        mergeSort(nums, mid + 1, right, temp);
        merge(nums, left, mid, right, temp);
    }

public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        std::vector<int> temp(nums.size());
        mergeSort(nums, 0, nums.size() - 1, temp);
        return nums;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna