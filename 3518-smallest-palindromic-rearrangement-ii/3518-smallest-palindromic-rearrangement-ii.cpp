#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    static constexpr long long MAX_K = 1e6 + 1;

    // Calculates nCr capped at MAX_K to prevent overflow
    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = std::min(r, n - r);
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - i + 1) / i;
            if (res >= MAX_K) return MAX_K;
        }
        return res;
    }

    // Calculates multinomial permutations of remaining characters, capped at MAX_K
    long long countArrangements(const std::vector<int>& freq) {
        int total = 0;
        for (int count : freq) {
            total += count;
        }

        long long res = 1;
        int current_len = total;
        for (int count : freq) {
            if (count > 0) {
                res *= nCr(current_len, count);
                if (res >= MAX_K) return MAX_K;
                current_len -= count;
            }
        }
        return res;
    }

public:
    std::string smallestPalindrome(std::string s, int k) {
        std::vector<int> char_counts(26, 0);
        for (char c : s) {
            char_counts[c - 'a']++;
        }

        std::vector<int> half_freq(26, 0);
        char mid_char = '\0';

        // Split character frequencies into the left half
        for (int i = 0; i < 26; ++i) {
            half_freq[i] = char_counts[i] / 2;
            if (char_counts[i] % 2 != 0) {
                mid_char = 'a' + i;
            }
        }

        // Check if there are at least k valid palindromic permutations
        long long total_permutations = countArrangements(half_freq);
        if (k > total_permutations) {
            return "";
        }

        int half_length = s.length() / 2;
        std::string left_half = "";

        // Construct left half character by character
        for (int pos = 0; pos < half_length; ++pos) {
            for (int ch = 0; ch < 26; ++ch) {
                if (half_freq[ch] == 0) continue;

                // Try placing character 'a' + ch
                half_freq[ch]--;
                long long arrangements = countArrangements(half_freq);

                if (arrangements >= k) {
                    left_half += (char)('a' + ch);
                    break; // Fixed this position, move to next position
                } else {
                    k -= arrangements;
                    half_freq[ch]++; // Backtrack and try next character
                }
            }
        }

        // Form complete palindrome
        std::string right_half = left_half;
        std::reverse(right_half.begin(), right_half.end());

        if (mid_char != '\0') {
            return left_half + mid_char + right_half;
        }
        return left_half + right_half;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna