// https://leetcode.com/problems/longest-palindromic-substring

// Two-pointer expand around center
// Time complexity: O(n^2)
// Space complexity: O(1)

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
			return "";

        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < s.size(); ++i) {
            expandAroundCenter(s, i, i, start, maxLength);

            expandAroundCenter(s, i, i + 1, start, maxLength);
        }

        return s.substr(start, maxLength);
    }
	
private:
    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLength) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }

        int currentLength = right - left - 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
            start = left + 1;
        }
    }
};



// Dynamic programming
// Time complexity: O(n^2)
// Space complexity: O(n^2)

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        vector<std::vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, maxLength = 1;

        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        for (int length = 3; length <= n; ++length) {
            for (int i = 0; i <= n - length; ++i) {
                int j = i + length - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLength = length;
                }
            }
        }

        return s.substr(start, maxLength);
    }
};