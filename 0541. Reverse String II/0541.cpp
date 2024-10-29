// https://leetcode.com/problems/reverse-string-ii

// Iterative reversal by segments
// Time: O(n)
// Space: O(1)

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();

        for (int i = 0; i < n; i += 2 * k) {
            int left = i;
            int right = min(i + k - 1, n - 1);
            while (left < right)
                swap(s[left++], s[right--]);
        }

        return s;
    }
};