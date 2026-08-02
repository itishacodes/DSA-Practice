class Solution {
public:
    int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {

        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());

        int n = seats.size();
        int sum = 0;

        for (int i=0; i<n; i++) {
            sum += std::abs(students[i] - seats[i]);
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna