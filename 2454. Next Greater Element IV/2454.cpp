// https://leetcode.com/problems/next-greater-element-iv/

// Two monotonic stack
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        vector<int> result(size(nums), -1);
        stack<int> stack1;
		stack<int> stack2;

        for (int i = 0; i < size(nums); ++i) {
            while (!stack2.empty() && nums[stack2.top()] < nums[i]) {
                result[stack2.top()] = nums[i];
                stack2.pop();
            }
			
            vector<int> temp;
            while (!stack1.empty() && nums[stack1.top()] < nums[i]) {
                temp.emplace_back(stack1.top());
                stack1.pop();
            }
			
            stack1.push(i);
            for (int j = temp.size() - 1; j >= 0; --j) {
                stack2.push(temp[j]);
            }
        }
        return result;
    }
};


