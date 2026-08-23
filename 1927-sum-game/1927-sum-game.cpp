#include <string>

class Solution {
public:
    bool sumGame(std::string num) {
        int n = num.length();
        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') leftQ++;
            else leftSum += num[i] - '0';
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') rightQ++;
            else rightSum += num[i] - '0';
        }

        // Total '?' must be even for Bob to have a chance
        if ((leftQ + rightQ) % 2 != 0) return true;

        // Simplify to net difference: (leftSum - rightSum) and (leftQ - rightQ)
        int sumDiff = leftSum - rightSum;
        int qDiff = leftQ - rightQ;

        // Bob wins if the extra '?' on one side can exactly absorb the sum deficit
        return (sumDiff + qDiff / 2 * 9 != 0);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna