class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        
        int n1 = g.size();
        int n2 = s.size();

        int i=0;
        int j=0;

        while (i < n1 && j < n2) {
            if (s[j] >= g[i]) {
                i++;
            }
            j++;
        }
        return i;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna