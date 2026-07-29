#include <algorithm>
#include <vector>

class Solution {
public:
    int heightChecker(std::vector<int>& heights) {

        std::vector<int> expected = heights;

        std::sort(expected.begin(), expected.end());

        int n = heights.size();
        int cnt = 0;

        for (int i=0; i<n; i++) {
            if (heights[i] != expected[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna