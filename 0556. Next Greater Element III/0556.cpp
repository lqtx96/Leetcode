// https://leetcode.com/problems/next-greater-element-iii/

// Next permutation
// Time: O(d) (d is the number of digits in n)
// Space: O(d)

class Solution {
public:
    int nextGreaterElement(int n) {
        string numStr = to_string(n);
        int length = numStr.size();

        int i = length - 2;
        while (i >= 0 && numStr[i] >= numStr[i + 1])
            --i;

        if (i < 0)
            return -1;

        int j = length - 1;
        while (numStr[j] <= numStr[i]) {
            --j;
        }

        swap(numStr[i], numStr[j]);
		
        reverse(numStr.begin() + i + 1, numStr.end());

        long long result = stoll(numStr);
        
        return (result > INT_MAX) ? -1 : static_cast<int>(result);
    }
};
