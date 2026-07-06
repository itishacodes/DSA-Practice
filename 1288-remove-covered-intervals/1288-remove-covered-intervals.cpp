#include <vector>
#include <algorithm>

class Solution {
public:
    int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
        // Custom comparator to sort intervals
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1]; // If starts are equal, larger end comes first
            }
            return a[0] < b[0]; // Otherwise, smaller start comes first
        });
        
        int remaining = intervals.size();
        int max_end = 0;
        
        for (const auto& interval : intervals) {
            // If the current interval's end is <= max_end seen so far,
            // it means it is fully covered because its start is >= previous starts.
            if (interval[1] <= max_end) {
                remaining--;
            } else {
                max_end = interval[1]; // Update the furthest boundary
            }
        }
        
        return remaining;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna