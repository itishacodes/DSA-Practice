class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        int r1x1 = rec1[0];
        int r1x2 = rec1[2];
        int r1y1 = rec1[1];
        int r1y2 = rec1[3];

        int r2x1 = rec2[0];
        int r2x2 = rec2[2];
        int r2y1 = rec2[1];
        int r2y2 = rec2[3];

        if (r1x1 >= r2x2) {
            return false;
        }

        if (r1x2 <= r2x1) {
            return false;
        }

        if (r1y2 <= r2y1) {
            return false;
        }

        if (r1y1 >= r2y2) {
            return false;
        }

        return true;

    }

};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna