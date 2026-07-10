
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Find the maximum possible value in nums to bound our arrays
        int maxVal = 0;
        for (int x : nums) {
            maxVal = max(maxVal, x);
        }

        // Mark which values exist in the graph
        vector<bool> exists(maxVal + 1, false);
        for (int x : nums) {
            exists[x] = true;
        }

        // last_exists[i] stores the largest existing value <= i
        vector<int> last_exists(maxVal + maxDiff + 1, -1);
        int last = -1;
        for (int i = 0; i <= maxVal + maxDiff; ++i) {
            if (i <= maxVal && exists[i]) {
                last = i;
            }
            last_exists[i] = last;
        }

        // up[j][v] stores the value reached from v after 2^j greedy steps to the right
        // 18 levels are enough since 2^17 > 100,000
        vector<vector<int>> up(18, vector<int>(maxVal + 1, -1));

        for (int v = 0; v <= maxVal; ++v) {
            if (exists[v]) {
                int limit = min(maxVal + maxDiff, v + maxDiff);
                up[0][v] = last_exists[limit];
            }
        }

        // Build the binary lifting table
        for (int j = 1; j < 18; ++j) {
            for (int v = 0; v <= maxVal; ++v) {
                if (exists[v] && up[j - 1][v] != -1) {
                    up[j][v] = up[j - 1][up[j - 1][v]];
                }
            }
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& q : queries) {
            int u = q[0], v = q[1];

            // Case 0: Same node
            if (u == v) {
                answer.push_back(0);
                continue;
            }

            int x = nums[u];
            int y = nums[v];

            // Case 1: Distinct nodes with the exact same value
            if (x == y) {
                answer.push_back(1);
                continue;
            }

            // Ensure x < y for unidirectional rightward binary lifting
            if (x > y) {
                swap(x, y);
            }

            // If even the maximum possible jumps cannot reach or exceed y
            if (up[17][x] < y) {
                answer.push_back(-1);
                continue;
            }

            int steps = 0;
            int curr = x;

            // Lift upwards as long as the destination is strictly less than y
            for (int j = 17; j >= 0; --j) {
                if (up[j][curr] != -1 && up[j][curr] < y) {
                    steps += (1 << j);
                    curr = up[j][curr];
                }
            }

            // One final step is needed to bridge the remaining gap to >= y
            steps += 1;
            answer.push_back(steps);
        }

        return answer;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna