#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;

        // dp_score[i][j] stores max score to reach (i, j) from 'S'
        // Initialize with -1 to represent unreachable states
        vector<vector<int>> dp_score(n, vector<int>(n, -1));
        // dp_count[i][j] stores the number of paths achieving that max score
        vector<vector<int>> dp_count(n, vector<int>(n, 0));

        // Base case: Start at the bottom-right corner 'S'
        dp_score[n - 1][n - 1] = 0;
        dp_count[n - 1][n - 1] = 1;

        // Directions to check: Down, Right, Down-Right
        int dr[] = {1, 0, 1};
        int dc[] = {0, 1, 1};

        // Traverse backward from bottom-right to top-left
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // Skip the start cell initialization logic and skip obstacles
                if (board[i][j] == 'X' || (i == n - 1 && j == n - 1)) {
                    continue;
                }

                int max_prev_score = -1;
                int paths_to_current = 0;

                // Look at the 3 paths coming into (i, j)
                for (int d = 0; d < 3; ++d) {
                    int prev_i = i + dr[d];
                    int prev_j = j + dc[d];

                    // Check bounds and if the previous cell is reachable
                    if (prev_i < n && prev_j < n && dp_score[prev_i][prev_j] != -1) {
                        if (dp_score[prev_i][prev_j] > max_prev_score) {
                            max_prev_score = dp_score[prev_i][prev_j];
                            paths_to_current = dp_count[prev_i][prev_j];
                        } else if (dp_score[prev_i][prev_j] == max_prev_score) {
                            paths_to_current = (paths_to_current + dp_count[prev_i][prev_j]) % MOD;
                        }
                    }
                }

                // If at least one valid path led to this cell
                if (max_prev_score != -1) {
                    int current_val = (board[i][j] == 'E') ? 0 : (board[i][j] - '0');
                    dp_score[i][j] = max_prev_score + current_val;
                    dp_count[i][j] = paths_to_current;
                }
            }
        }

        // If 'E' at (0, 0) is unreachable, return [0, 0]
        if (dp_score[0][0] == -1) {
            return {0, 0};
        }

        return {dp_score[0][0], dp_count[0][0]};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna