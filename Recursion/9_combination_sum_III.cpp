class Solution {
public:
    void helper(int i, int k, int sumTillNow, vector<int> &sub, vector<vector<int>>&ans, int n){
        // ans case
        if (sumTillNow == n && k == 0) {
            ans.push_back(sub);
            return;
        }
        // ***add prune condition below
        if(k<0 || i>9 || sumTillNow>n) return;

        // pick
        sub.push_back(i);
        helper(i+1, k-1, sumTillNow+i, sub, ans, n);

        sub.pop_back();
        helper(i+1, k, sumTillNow, sub, ans, n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> sub;
        helper(1,k,0,sub, ans,n);
        return ans;
    }
};
