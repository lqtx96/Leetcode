// https://leetcode.com/problems/reverse-string/description

// Cheat solution using function in STL
// Time: O(n)
// Space: O(1)

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};



// Two pointer
// Time: O(n)
// Space: O(1)

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
};


