// TC: O(n log n + 2^n * n)
// SC: O(n)

class Solution {
public:
    void recursion(int i, int target, vector<int>& candidates, vector<int>& sub,
                   vector<vector<int>>& ans) {
        // base case
        if (target == 0) {
            ans.push_back(sub);
            return;
        }

        // failure condition
        if (i == candidates.size())
            return;

        if (candidates[i] <= target) {
            sub.push_back(candidates[i]);
            // pick
            recursion(i + 1, target - candidates[i], candidates,sub, ans);
            sub.pop_back();
        }

        // skip duplicates
        while(i+1 < candidates.size() && candidates[i] == candidates[i+1]){
            i++;
        }
        // not pick
        recursion(i+1, target, candidates,sub, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // At each index, either Pick (if ≤ target) or Not Pick (skip all
        // duplicates), with base    case target == 0 → store answer.
        
        // sort 
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> sub;
        recursion(0, target, candidates, sub, ans);
        return ans;
    }
};
