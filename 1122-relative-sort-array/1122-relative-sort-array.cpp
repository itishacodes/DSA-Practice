class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> freq;  // unordered map initialised
        for (auto it : arr1) freq[it]++;  // put all elements of arr1 in hashmap with elements and its frequency

        vector<int> ans;  // array created for answer storage
        for (auto it : arr2) {   // putting elememts of arr1 in the hashmap as per the order in arr2
            while (freq[it]--) {
                ans.push_back(it); 
            }
        }

        for (auto& [it, f] : freq) {   // if elements not in arr2 but exists in arr1 then put them as well in the hashmap in increasing order 
            while (f>0 && f--) {
                ans.push_back(it);
            }
        }

        return ans;
    }
};

// TC = O(n log n + m)
// SC = O(n)

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna