// TC: O(2^n)
// SC: O(n)

// -> we are backtracking as we need to take decision based on prev decision

class Solution {
public:
    void helper(int i, vector<int>& nums, vector<int>& sub,
                vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(sub);
            return;
        }

        else {
            // pick
            sub.push_back(nums[i]);
            helper(i + 1, nums, sub, ans);

            sub.pop_back(); // backtrack

            // skip duplicates
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i++;
            };
            // not pick
            helper(i + 1, nums, sub, ans);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> sub;
        helper(0, nums, sub, ans);
        return ans;
    }
};
