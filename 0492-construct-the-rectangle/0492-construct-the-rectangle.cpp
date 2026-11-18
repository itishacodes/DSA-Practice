class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = std::sqrt(area);

        while (area % w != 0) {
            w--;
        }

        int l = area/w;

        return {l,w};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna