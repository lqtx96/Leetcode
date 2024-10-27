// Monotonic stack
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        constexpr int kMod = 1'000'000'007; // Modulus for the result
        const int n = arr.size();
        long totalSum = 0;
        
        vector<int> previousMin(n, -1);
        vector<int> nextMin(n, n);
        stack<int> minIndexStack;

        for (int i = 0; i < n; ++i) {
            while (!minIndexStack.empty() && arr[minIndexStack.top()] > arr[i]) {
                int index = minIndexStack.top();
                minIndexStack.pop();
                nextMin[index] = i;
            }
            if (!minIndexStack.empty()) {
                previousMin[i] = minIndexStack.top();
            }
            minIndexStack.push(i);
        }

        for (int i = 0; i < n; ++i) {
            long contribution = static_cast<long>(arr[i]) * (i - previousMin[i]) * (nextMin[i] - i);
            totalSum = (totalSum + contribution) % kMod;
        }

        return totalSum;
    }
};
