#include <vector>
#include <algorithm>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        int n = citations.size();

        for (int i = 0; i < n; ++i) {
            // Number of papers with at least citations[i] citations is (n - i)
            if (citations[i] >= n - i) {
                return n - i;
            }
        }

        return 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna