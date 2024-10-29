// https://leetcode.com/problems/next-permutation

// Cheat solution (using next_permutation() function from STL)
// Time: O(n)
// Space: O(1)

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        next_permutation(num.begin(), num.end());
    }
};



// Next permutation
// Time: O(n)
// Space: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& num) {
        int n = num.size();
        int i = n - 2;
        
        while (i >= 0 && num[i] >= num[i + 1])
            i--;
        
        if (i >= 0) {
            int j = n - 1;
            while (num[j] <= num[i])
                j--;
            swap(num[i], num[j]);
        }
        
        reverse(num.begin() + i + 1, num.end());
    }
};