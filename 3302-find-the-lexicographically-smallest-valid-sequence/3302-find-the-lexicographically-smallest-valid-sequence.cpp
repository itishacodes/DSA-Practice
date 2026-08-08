#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> validSequence(std::string word1, std::string word2) {
        int n = word1.size();
        int m = word2.size();

        // last[j] stores the maximum index in word1 that can match word2[j...m-1]
        std::vector<int> last(m, -1);

        // Step 1: Precompute last matching positions from right to left
        int w1_idx = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            while (w1_idx >= 0 && word1[w1_idx] != word2[j]) {
                w1_idx--;
            }
            if (w1_idx >= 0) {
                last[j] = w1_idx;
                w1_idx--; // Move to next available character in word1
            }
        }

        std::vector<int> result;
        bool usedChange = false;
        int j = 0;

        // Step 2: Greedily pick the smallest indices from left to right
        for (int i = 0; i < n && j < m; ++i) {
            bool matches = (word1[i] == word2[j]);

            // Case A: Exact character match
            if (matches) {
                result.push_back(i);
                j++;
            } 
            // Case B: Mismatch, try to spend our 1 modification here
            else if (!usedChange) {
                // Check if remaining suffix word2[j+1...m-1] can fit after position i
                bool canFitRemaining = (j + 1 == m) || (last[j + 1] > i);

                if (canFitRemaining) {
                    usedChange = true;
                    result.push_back(i);
                    j++;
                }
            }
        }

        // If we matched all characters of word2, return sequence; otherwise invalid
        if (result.size() == m) {
            return result;
        }
        return {};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna