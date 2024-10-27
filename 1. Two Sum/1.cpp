// Two-pointer
// Time complexity: O(n*(log(n)), O(n) in the worst case (iterate through the vector with two pointers from both ends until they meet)
// Space complexity: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Pair each number with its index and sort
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); ++i) {
            indexedNums.emplace_back(nums[i], i);
        }
        
        sort(indexedNums.begin(), indexedNums.end());

        int left = 0;
        int right = indexedNums.size() - 1;

        while (left < right) {
            int sum = indexedNums[left].first + indexedNums[right].first;
            if (sum == target) {
                return {indexedNums[left].second, indexedNums[right].second};
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
        
        return {};
    }
};



// Hash map
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Maps value to its index
        unordered_map<int, int> num_map;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }
            
            num_map[nums[i]] = i;
        }
        
        return {};
    }
};

