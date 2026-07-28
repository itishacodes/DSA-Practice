#include <string>
#include <algorithm>

class Solution {
public:
    std::string smallestPalindrome(std::string s) {
        int n = s.length();
        int half = n / 2;
        
        // Extract the first half of the string
        std::string left = s.substr(0, half);
        
        // Sort the first half lexicographically
        std::sort(left.begin(), left.end());
        
        // Create the right half by reversing the sorted left half
        std::string right = left;
        std::reverse(right.begin(), right.end());
        
        // If string length is odd, place the original middle character in the center
        if (n % 2 == 1) {
            return left + s[half] + right;
        }
        
        return left + right;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna