// Monotonic stack + hash map
// Time complexity: O(n+m)
// Space complexity: O(m)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> nextGreaterMap;
        stack<int> decreasingStack;

        for (const int num : nums2) {
            while (!decreasingStack.empty() && decreasingStack.top() < num) {
                nextGreaterMap[decreasingStack.top()] = num;
                decreasingStack.pop();
            }
            decreasingStack.push(num);
        }

        for (const int num : nums1) {
            auto it = nextGreaterMap.find(num);
            result.push_back(it != nextGreaterMap.end() ? it->second : -1);
        }

        return result;
    }
};