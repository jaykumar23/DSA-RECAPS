class Solution {
public:
    void recursion(int indx, int target,vector<int>& candidates, vector<int>&sub, vector<vector<int>>&ans, int n){
        // base condition
        if(indx == n){
            if(target == 0){
                ans.push_back(sub);
            }
            return;
        }

        if(candidates[indx] <= target){
            sub.push_back(candidates[indx]);
            // pick 
            recursion(indx, target-candidates[indx], candidates, sub, ans, n);
            sub.pop_back();
        }
        // not pick
        recursion(indx+1, target, candidates, sub, ans, n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sub;
        int n = candidates.size();
        recursion(0, target, candidates, sub, ans, n);
        return ans;
    }
};
