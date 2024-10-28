// https://leetcode.com/problems/sum-of-total-strength-of-wizards/

// Monotonic stack
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    int totalStrength(std::vector<int>& strength) {
        constexpr int kMod = 1'000'000'007;
        const int n = strength.size();

        vector<long> prefix(n);
        vector<long> prefixOfPrefix(n + 1, 0);

        std::vector<int> left(n, -1);
        std::vector<int> right(n, n);
        std::stack<int> indexStack;

        for (int i = 0; i < n; ++i) {
            prefix[i] = (i == 0) ? strength[i] : (strength[i] + prefix[i - 1]) % kMod;
        }

        for (int i = 0; i < n; ++i) {
            prefixOfPrefix[i + 1] = (prefixOfPrefix[i] + prefix[i]) % kMod;
        }

        for (int i = n - 1; i >= 0; --i) {
            while (!indexStack.empty() && strength[indexStack.top()] >= strength[i]) {
                left[indexStack.top()] = i;
                indexStack.pop();
            }
            indexStack.push(i);
        }

        indexStack = std::stack<int>();

        for (int i = 0; i < n; ++i) {
            while (!indexStack.empty() && strength[indexStack.top()] > strength[i]) {
                right[indexStack.top()] = i;
                indexStack.pop();
            }
            indexStack.push(i);
        }

        long result = 0;
        for (int i = 0; i < n; ++i) {
            const int l = left[i];
            const int r = right[i];

            long leftSum = (prefixOfPrefix[i] - prefixOfPrefix[std::max(0, l)]) % kMod;
            long rightSum = (prefixOfPrefix[r] - prefixOfPrefix[i]) % kMod;

            int leftLen = i - l;
            int rightLen = r - i;

            result = ((result + strength[i] * ((rightSum * leftLen % kMod - leftSum * rightLen % kMod + kMod) % kMod)) % kMod) % kMod;
        }

        return result;
    }
};
