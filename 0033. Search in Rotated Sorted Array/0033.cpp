// https://leetcode.com/problems/search-in-rotated-sorted-array

// Linear search (Leetcode still accepts this solution, but it is not O(logn) so this is a cheat
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target)
                return i;
        }
        return -1;
    }
};



// Binary search
// Time: O(logn)
// Space: O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int middle = left + (right - left) / 2;

            if (nums[middle] == target)
                return middle;

            if (nums[left] <= nums[middle]) {
                if (nums[left] <= target && target < nums[middle])
                    right = middle - 1;
                else
                    left = middle + 1;
            }
            else {
                if (nums[middle] < target && target <= nums[right])
                    left = middle + 1;
                else
                    right = middle - 1;
            }
        }

        return -1;
    }
};
