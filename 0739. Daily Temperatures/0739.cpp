// https://leetcode.com/problems/daily-temperatures

// Monotonic stack
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> decreasingStack;

        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (!decreasingStack.empty() && temperatures[i] >= temperatures[decreasingStack.top()])
                decreasingStack.pop();
            if (!decreasingStack.empty())
                result[i] = decreasingStack.top() - i;
            decreasingStack.push(i);
        }

        return result;
    }
};