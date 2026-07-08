#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        long long MOD = 1e9 + 7;

        // Precompute powers of 10
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        // Prefix arrays
        vector<int> sumD(n + 1, 0);     // Prefix sum of digits
        vector<int> cntN0(n + 1, 0);    // Prefix count of non-zero digits
        vector<long long> p(n + 1, 0);  // Prefix number formed by non-zero digits

        for (int i = 1; i <= n; i++) {
            int d = s[i - 1] - '0';
            sumD[i] = sumD[i - 1] + d;
            cntN0[i] = cntN0[i - 1] + (d > 0 ? 1 : 0);
            p[i] = (d > 0) ? (p[i - 1] * 10 + d) % MOD : p[i - 1];
        }

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            int n0 = cntN0[r + 1] - cntN0[l];
            long long sd = sumD[r + 1] - sumD[l];
            
            // Extract x using the prefix subtraction logic
            long long x = (p[r + 1] - (p[l] * pow10[n0]) % MOD + MOD) % MOD;

            ans[i] = (x * sd) % MOD;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna