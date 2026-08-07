#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
private:
    struct Factor {
        long long c2 = 0, c3 = 0, c5 = 0, c7 = 0;
    };

    Factor getFactors(long long n) {
        Factor f;
        while (n % 2 == 0) { f.c2++; n /= 2; }
        while (n % 3 == 0) { f.c3++; n /= 3; }
        while (n % 5 == 0) { f.c5++; n /= 5; }
        while (n % 7 == 0) { f.c7++; n /= 7; }
        if (n > 1) return {-1, -1, -1, -1};
        return f;
    }

    Factor getDigitFactors(int d) {
        if (d == 2) return {1, 0, 0, 0};
        if (d == 3) return {0, 1, 0, 0};
        if (d == 4) return {2, 0, 0, 0};
        if (d == 5) return {0, 0, 1, 0};
        if (d == 6) return {1, 1, 0, 0};
        if (d == 7) return {0, 0, 0, 1};
        if (d == 8) return {3, 0, 0, 0};
        if (d == 9) return {0, 2, 0, 0};
        return {0, 0, 0, 0};
    }

    // Returns minimum number of digits needed to cover required factors
    int getMinLength(Factor req) {
        long long c2 = std::max(0LL, req.c2);
        long long c3 = std::max(0LL, req.c3);
        long long c5 = std::max(0LL, req.c5);
        long long c7 = std::max(0LL, req.c7);

        // Maximize 8s (2^3) and 9s (3^2) to find min length
        int len = c5 + c7;
        len += (c3 + 1) / 2; // ceil(c3 / 2)
        
        long long rem_c2 = c2;
        if (c3 % 2 == 1) {
            // A remaining '3' could pair with a '2' to form '6'
            rem_c2 = std::max(0LL, rem_c2 - 1);
        }
        len += (rem_c2 + 2) / 3; // ceil(rem_c2 / 3)

        return len;
    }

    // Generates the optimal (smallest numerical value) sorted suffix
    std::string getMinSuffixDigits(Factor req) {
        long long c2 = std::max(0LL, req.c2);
        long long c3 = std::max(0LL, req.c3);
        long long c5 = std::max(0LL, req.c5);
        long long c7 = std::max(0LL, req.c7);

        int targetLen = getMinLength({c2, c3, c5, c7});
        if (targetLen == 0) return "";

        std::string res = "";
        Factor curReq = {c2, c3, c5, c7};

        for (int pos = 0; pos < targetLen; ++pos) {
            int remLen = targetLen - 1 - pos;

            for (int d = 1; d <= 9; ++d) {
                Factor df = getDigitFactors(d);
                Factor nextReq = {
                    std::max(0LL, curReq.c2 - df.c2),
                    std::max(0LL, curReq.c3 - df.c3),
                    std::max(0LL, curReq.c5 - df.c5),
                    std::max(0LL, curReq.c7 - df.c7)
                };

                if (getMinLength(nextReq) <= remLen) {
                    res += std::to_string(d);
                    curReq = nextReq;
                    break;
                }
            }
        }
        return res;
    }

public:
    std::string smallestNumber(std::string num, long long t) {
        Factor target = getFactors(t);
        if (target.c2 == -1) return "-1";

        int n = num.size();

        int firstZero = -1;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                firstZero = i;
                break;
            }
        }

        std::vector<Factor> pref(n + 1);
        int limit = (firstZero == -1) ? n : firstZero;

        for (int i = 0; i < limit; ++i) {
            Factor df = getDigitFactors(num[i] - '0');
            pref[i + 1] = {
                pref[i].c2 + df.c2,
                pref[i].c3 + df.c3,
                pref[i].c5 + df.c5,
                pref[i].c7 + df.c7
            };
        }

        for (int i = limit; i >= 0; --i) {
            int startDigit = (i == n) ? (num[n - 1] - '0') : (num[i] - '0' + 1);

            for (int d = startDigit; d <= 9; ++d) {
                if (d == 0) continue;

                Factor curPref = (i == n) ? pref[n] : pref[i];
                if (i < n) {
                    Factor df = getDigitFactors(d);
                    curPref.c2 += df.c2;
                    curPref.c3 += df.c3;
                    curPref.c5 += df.c5;
                    curPref.c7 += df.c7;
                }

                Factor needed = {
                    target.c2 - curPref.c2,
                    target.c3 - curPref.c3,
                    target.c5 - curPref.c5,
                    target.c7 - curPref.c7
                };

                std::string minSuff = getMinSuffixDigits(needed);
                int remLen = (i == n) ? 0 : (n - 1 - i);

                if ((int)minSuff.size() <= remLen) {
                    std::string res = num.substr(0, i);
                    if (i < n) res += std::to_string(d);
                    
                    int ones = remLen - (int)minSuff.size();
                    res += std::string(ones, '1') + minSuff;
                    return res;
                }
            }
        }

        std::string minSuff = getMinSuffixDigits(target);
        int totalLen = std::max((int)num.size() + 1, (int)minSuff.size());
        int ones = totalLen - (int)minSuff.size();

        return std::string(ones, '1') + minSuff;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna