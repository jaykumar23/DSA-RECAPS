TC: O(n * n!)
SC: O(n)

class Solution {
public:
    void backTrack(vector<int>& nums, vector<vector<int>>& ans,
                   vector<bool>& picked, vector<int>& sub) {
        // base condition
        if (sub.size() == nums.size()) {
            ans.push_back(sub);
            return;
        }

        // try with every possible number
        for (int i = 0; i < nums.size(); i++) {
            if (!picked[i]) {
                // choose
                sub.push_back(nums[i]);
                picked[i] = true;
                // explore
                backTrack(nums, ans, picked, sub);
                // undo
                sub.pop_back();
                picked[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> picked(nums.size(), false);
        vector<int> sub;
        backTrack(nums, ans, picked, sub);
        return ans;
    }
};
