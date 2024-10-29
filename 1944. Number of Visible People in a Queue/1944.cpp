// https://leetcode.com/problems/number-of-visible-people-in-a-queue

// Monotonic stack
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        const int n = heights.size();
        vector<int> visibleCounts(n, 0);
        stack<int> heightStack;

        for (int i = 0; i < n; ++i) {
            while (!heightStack.empty() && heights[heightStack.top()] <= heights[i]) {
                ++visibleCounts[heightStack.top()]; 
                heightStack.pop();
            }
            
            if (!heightStack.empty()) {
                ++visibleCounts[heightStack.top()];
            }
            
            heightStack.push(i);
        }

        return visibleCounts;
    }
};
