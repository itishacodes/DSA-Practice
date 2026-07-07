class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        long long multiplier = 1;
        
        while (n > 0) {
            int digit = n % 10;
            
            if (digit != 0) {
                sum += digit;
                x += digit * multiplier;
                multiplier *= 10;
            }
            
            n /= 10;
        }
        
        return x * sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna