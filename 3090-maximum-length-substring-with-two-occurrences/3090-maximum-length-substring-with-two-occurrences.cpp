#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumLengthSubstring(std::string s) {
        std::vector<int> count(26, 0);
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            count[s[right] - 'a']++;

            // Shrink window if any character occurs more than twice
            while (count[s[right] - 'a'] > 2) {
                count[s[left] - 'a']--;
                left++;
            }

            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna