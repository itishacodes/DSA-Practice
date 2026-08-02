class Solution {
public:
    int maxIceCream(std::vector<int>& costs, int coins) {
        int n = costs.size();
        std::sort(costs.begin(), costs.end());
        long sum = 0;
        int cnt = 0;

        for (int i=0; i<n; i++) {
            sum = sum + costs[i];

            if (sum <= coins) {
                cnt++;
            }
        }
        return cnt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna