#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<bool> pathExistenceQueries(int n, std::vector<int>& nums, int maxDiff, std::vector<std::vector<int>>& queries) {
        // compId[i] will store the component identifier for node i
        std::vector<int> compId(n, 0);
        int currentId = 0;
        
        // Step 1: Preprocess and assign component IDs
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                currentId++; // Found a gap, start a new component
            }
            compId[i] = currentId;
        }
        
        // Step 2: Answer each query in O(1) time
        std::vector<bool> answer;
        answer.reserve(queries.size());
        
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            // Path exists if they are in the same connected component
            answer.push_back(compId[u] == compId[v]);
        }
        
        return answer;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna