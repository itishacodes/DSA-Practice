#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::string smallestSubsequence(std::string s) {
        std::vector<int> last_occurrence(26, 0);
        std::vector<bool> visited(26, false);
        
        // Step 1: Record the last position of each character
        for (int i = 0; i < s.length(); ++i) {
            last_occurrence[s[i] - 'a'] = i;
        }
        
        std::string result = "";
        
        // Step 2: Build the result using a stack-like approach
        for (int i = 0; i < s.length(); ++i) {
            int char_idx = s[i] - 'a';
            
            // If already in the result, skip
            if (visited[char_idx]) continue;
            
            // While stack is not empty AND
            // current char is smaller than top of stack AND
            // the top character appears later in the string
            while (!result.empty() && s[i] < result.back() && i < last_occurrence[result.back() - 'a']) {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            // Add current character
            result.push_back(s[i]);
            visited[char_idx] = true;
        }
        
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna