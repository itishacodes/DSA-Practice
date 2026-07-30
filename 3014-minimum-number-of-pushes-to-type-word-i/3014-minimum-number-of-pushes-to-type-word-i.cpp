#include <string>

class Solution {
public:
    int minimumPushes(std::string word) {
        int n = word.length();
        int pushes = 0;

        for (int i = 0; i < n; i++) {
            // (i / 8) + 1 calculates the push cost:
            // i from 0 to 7   -> 1 push
            // i from 8 to 15  -> 2 pushes
            // i from 16 to 23 -> 3 pushes
            // i from 24 to 25 -> 4 pushes
            pushes += (i / 8) + 1;
        }

        return pushes;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna