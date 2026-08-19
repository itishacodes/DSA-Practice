#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxNumberOfFamilies(int n, std::vector<std::vector<int>>& reservedSeats) {
        // Map row number to bitmask of reserved seats
        std::unordered_map<int, int> reservedMap;

        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            reservedMap[row] |= (1 << col);
        }

        // Start by assuming all n rows are empty (each holds 2 families)
        int maxGroups = (n - reservedMap.size()) * 2;

        for (auto& [row, mask] : reservedMap) {
            bool leftPossible   = !(mask & (1 << 2)) && !(mask & (1 << 3)) && 
                                  !(mask & (1 << 4)) && !(mask & (1 << 5));
            
            bool rightPossible  = !(mask & (1 << 6)) && !(mask & (1 << 7)) && 
                                  !(mask & (1 << 8)) && !(mask & (1 << 9));
            
            bool middlePossible = !(mask & (1 << 4)) && !(mask & (1 << 5)) && 
                                  !(mask & (1 << 6)) && !(mask & (1 << 7));

            if (leftPossible && rightPossible) {
                maxGroups += 2; // Both left and right fit
            } else if (leftPossible || rightPossible || middlePossible) {
                maxGroups += 1; // At least one block fits
            }
        }

        return maxGroups;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna