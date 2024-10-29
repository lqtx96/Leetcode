// https://leetcode.com/problems/sort-vowels-in-a-string

// Two pointer
// Time: O(nlogn)
// Space: O(v) (v is the number of vowels)

class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        string vowelsSet = "aeiouAEIOU";

        for (char c : s) {
            if (vowelsSet.find(c) != string::npos)
                vowels.push_back(c);
        }

        sort(vowels.begin(), vowels.end());

        int index = 0;
        for (char &c : s) {
            if (vowelsSet.find(c) != string::npos)
                c = vowels[index++];
        }

        return s;
    }
};