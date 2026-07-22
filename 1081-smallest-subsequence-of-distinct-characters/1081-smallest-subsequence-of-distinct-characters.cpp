#include <string>
#include <vector>

class Solution {
public:
    std::string smallestSubsequence(std::string s) {
        std::vector<int> last_index(26, 0);
        std::vector<bool> in_stack(26, false);
        
        // Step 1: Record the last occurrence index for each character
        for (int i = 0; i < s.length(); ++i) {
            last_index[s[i] - 'a'] = i;
        }
        
        std::string result = ""; // Used as a stack
        
        // Step 2: Iterate through the string
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            
            // If character is already included in our result, skip it
            if (in_stack[c - 'a']) continue;
            
            // Maintain monotonic property: pop larger characters that appear again later
            while (!result.empty() && result.back() > c && last_index[result.back() - 'a'] > i) {
                in_stack[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            // Append current character
            result.push_back(c);
            in_stack[c - 'a'] = true;
        }
        
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna