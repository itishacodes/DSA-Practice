#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> sequentialDigits(int low, int high) {
        std::vector<int> result;
        
        // Loop through all possible lengths of sequential numbers (from 2 digits to 9 digits)
        for (int length = 2; length <= 9; ++length) {
            // Loop through all possible starting digits
            for (int startDigit = 1; startDigit <= 10 - length; ++startDigit) {
                int num = 0;
                int currentDigit = startDigit;
                
                // Construct the sequential number of the current length
                for (int i = 0; i < length; ++i) {
                    num = num * 10 + currentDigit;
                    currentDigit++;
                }
                
                // If it falls within our range, save it
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna