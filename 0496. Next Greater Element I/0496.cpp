// https://leetcode.com/problems/next-greater-element-i/

// Monotonic stack + hash map
// Time complexity: O(n+m)
// Space complexity: O(m)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    unordered_map<int, int> nextGreaterMap;
    stack<int> decreasingStack;

    for (int i = nums2.size() - 1; i >= 0; --i) {
        while (!decreasingStack.empty() && nums2[i] >= decreasingStack.top())
            decreasingStack.pop();

        if (!decreasingStack.empty())            
            nextGreaterMap[nums2[i]] = decreasingStack.top();
        else
            nextGreaterMap[nums2[i]] = -1;
            
        decreasingStack.push(nums2[i]);
    }

    for (int i = 0; i < nums1.size(); ++i)
        result.push_back(nextGreaterMap[nums1[i]]);

    return result;
    }
};