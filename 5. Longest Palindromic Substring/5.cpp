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
            // Check for odd-length palindromes
            expandAroundCenter(s, i, i, start, maxLength);

            // Check for even-length palindromes
            expandAroundCenter(s, i, i + 1, start, maxLength);
        }

        return s.substr(start, maxLength);
    }

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

        // Every single character is a palindrome
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        // Check for palindromic substrings of length 2
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Check for substrings of length 3 and greater
        for (int length = 3; length <= n; ++length) {  // length of the substring
            for (int i = 0; i <= n - length; ++i) {
                int j = i + length - 1;  // ending index of the substring
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