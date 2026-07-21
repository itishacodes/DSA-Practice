#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxActiveSectionsAfterTrade(std::string s) {
        int n = s.length();
        
        // Count initial '1's in original s
        int initial_ones = 0;
        for (char c : s) {
            if (c == '1') initial_ones++;
        }
        
        // Build augmented string t = "1" + s + "1"
        std::string t = "1" + s + "1";
        
        // Compress t into blocks of (char, length)
        std::vector<std::pair<char, int>> blocks;
        for (int i = 0; i < t.length(); ) {
            int j = i;
            while (j < t.length() && t[j] == t[i]) {
                j++;
            }
            blocks.push_back({t[i], j - i});
            i = j;
        }
        
        int max_gain = 0;
        
        // A trade requires pattern: '0' block, '1' block, '0' block
        // The '1' block must be surrounded by '0's inside t, meaning it cannot be 
        // the first block or the last block of t.
        for (size_t i = 1; i + 1 < blocks.size(); ++i) {
            if (blocks[i].first == '1') {
                // blocks[i-1] is '0' block, blocks[i+1] is '0' block
                int zeros_gained = blocks[i - 1].second + blocks[i + 1].second;
                max_gain = std::max(max_gain, zeros_gained);
            }
        }
        
        return initial_ones + max_gain;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna