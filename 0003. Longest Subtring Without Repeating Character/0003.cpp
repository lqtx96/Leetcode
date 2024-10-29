// https://leetcode.com/problems/longest-substring-without-repeating-characters

// Sliding window
// Time complexity: O(n^2)
// Space complexity: O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int left = 0;
		int right = 0;
        
        for (right; right < s.size(); ++right) {
            string currentSubstring = s.substr(left, right - left);
            size_t position = currentSubstring.find(s[right]);
            
            if (position != string::npos) {
                left += position + 1;
            }
            
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};



// Hash map
// Time complexity: O(n)
// Space complexity: O(min(n,m))

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> characterMap;
        int maxLength = 0;
        int left = -1;

        for (int right = 0; right < s.size(); ++right) {
            if (characterMap.find(s[right]) != characterMap.end()) {
                left = max(left, characterMap[s[right]]);
            }
            characterMap[s[right]] = right;
            maxLength = max(maxLength, right - left);
        }

        return maxLength;
    }
};



// Sliding window + Hash map
// Time complexity: O(n)
// Space complexity: O(min(n,m))

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> characterMap;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.size(); ++right) {
            if (characterMap.find(s[right]) != characterMap.end() && characterMap[s[right]] >= left) {
                left = characterMap[s[right]] + 1;
            }
            characterMap[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};