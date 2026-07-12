#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        std::vector<int> sorted_arr = arr;
        std::sort(sorted_arr.begin(), sorted_arr.end());
        sorted_arr.erase(std::unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());

        for (int& num : arr) {
            // lower_bound finds the iterator to the element, 
            // distance gives its 0-based index, + 1 gives the rank.
            num = std::lower_bound(sorted_arr.begin(), sorted_arr.end(), num) - sorted_arr.begin() + 1;
        }

        return arr;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna