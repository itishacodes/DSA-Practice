#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumPushes(std::string word) {
        // Step 1: Count frequency of each character
        std::vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }

        // Step 2: Sort frequencies in descending order
        std::sort(freq.rbegin(), freq.rend());

        // Step 3: Calculate minimum pushes required
        int totalPushes = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] == 0) break; // No more unique characters left

            // Position multiplier:
            // i from 0..7  -> (0/8 + 1) = 1 push
            // i from 8..15 -> (8/8 + 1) = 2 pushes
            // i from 16..23 -> (16/8 + 1) = 3 pushes
            // i from 24..25 -> (24/8 + 1) = 4 pushes
            int pushesPerChar = (i / 8) + 1;
            totalPushes += freq[i] * pushesPerChar;
        }

        return totalPushes;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna