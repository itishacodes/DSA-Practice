#include <vector>
#include <string>
#include <algorithm>

struct Node {
    int max_len = 1;
    int pref_len = 1;
    int suff_len = 1;
    char left_char = 0;
    char right_char = 0;
    int len = 1;
};

class SegmentTree {
private:
    int n;
    std::vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.len = left.len + right.len;
        res.left_char = left.left_char;
        res.right_char = right.right_char;

        // Base max length from either half
        res.max_len = std::max(left.max_len, right.max_len);

        // Calculate prefix length
        res.pref_len = left.pref_len;
        if (left.pref_len == left.len && left.right_char == right.left_char) {
            res.pref_len = left.len + right.pref_len;
        }

        // Calculate suffix length
        res.suff_len = right.suff_len;
        if (right.suff_len == right.len && left.right_char == right.left_char) {
            res.suff_len = right.len + left.suff_len;
        }

        // Cross-boundary merge check
        if (left.right_char == right.left_char) {
            res.max_len = std::max(res.max_len, left.suff_len + right.pref_len);
        }

        return res;
    }

    void build(int node, int start, int end, const std::string& s) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start], 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node].left_char = ch;
            tree[node].right_char = ch;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    SegmentTree(const std::string& s) {
        n = s.length();
        tree.resize(4 * n);
        build(1, 0, n - 1, s);
    }

    void updateChar(int idx, char ch) {
        update(1, 0, n - 1, idx, ch);
    }

    int getMax() const {
        return tree[1].max_len;
    }
};

class Solution {
public:
    std::vector<int> longestRepeating(std::string s, std::string queryCharacters, std::vector<int>& queryIndices) {
        SegmentTree st(s);
        int k = queryIndices.size();
        std::vector<int> result(k);

        for (int i = 0; i < k; ++i) {
            st.updateChar(queryIndices[i], queryCharacters[i]);
            result[i] = st.getMax();
        }

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna