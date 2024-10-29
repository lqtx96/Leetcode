// https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet

// Monotonic stack
// Time: O(n + qlogq) (n is number of building and q is number of queries)
// Space: O(n)

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<pair<int, int>>& queries) {
        int n = heights.size();
        vector<int> result;

        for (const auto& [aliceStart, bobStart] : queries) {
            int alice = min(aliceStart, bobStart);
            int bob = max(aliceStart, bobStart);
            stack<int> candidateBuildings;
            
            for (int i = alice; i <= bob; ++i) {
                while (!candidateBuildings.empty() && heights[candidateBuildings.top()] <= heights[i])
                    candidateBuildings.pop();
                candidateBuildings.push(i);
            }

            int left = 0, right = candidateBuildings.size() - 1;
            int meetingBuilding = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (candidateBuildings[mid] >= alice && candidateBuildings[mid] <= bob) {
                    meetingBuilding = candidateBuildings[mid];
                    right = mid - 1;
                } else
                    left = mid + 1;
            }

            result.push_back(meetingBuilding);
        }
        
        return result;
    }
};


