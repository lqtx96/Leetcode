// Monotonic stack
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return calculateSubarraySum(nums, less<int>()) - calculateSubarraySum(nums, greater<int>());
    }

private:
    long long calculateSubarraySum(const vector<int>& arr, const function<bool(int, int)>& comparator) {
        const int n = arr.size();
        long long totalSum = 0;
        vector<int> previous(n, -1);
        vector<int> next(n, n);
        stack<int> indexStack;

        for (int i = 0; i < n; ++i) {
            while (!indexStack.empty() && comparator(arr[indexStack.top()], arr[i])) {
                int index = indexStack.top();
                indexStack.pop();
                next[index] = i;
            }
            if (!indexStack.empty()) {
                previous[i] = indexStack.top();
            }
            indexStack.push(i);
        }

        for (int i = 0; i < n; ++i) {
            totalSum += static_cast<long long>(arr[i]) * (i - previous[i]) * (next[i] - i);
        }

        return totalSum;
    }
};
