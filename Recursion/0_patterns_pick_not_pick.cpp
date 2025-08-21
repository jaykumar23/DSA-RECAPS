// https://leetcode.com/problems/subsets/description/
// O(2^N)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        int index = 0;
        int n = nums.size();

        recursion(index, n, sub, res, nums);

        return res;
    }
    void recursion(int index, int n, vector<int> &sub, vector<vector<int>> &res,vector<int>& nums){
        // base case
        if(index>=n){
            res.push_back(sub);
            return;
        }
        // take
        sub.push_back(nums[index]);
        recursion(index+1, n, sub, res, nums);

        // not take
        sub.pop_back();
        recursion(index+1, n, sub, res, nums);
    }
};



// take / not take recursion pattern with a single answer →
// Time Complexity: O(2^n) worst case
// Space Complexity: O(n)
bool recursion(int i, vector<int>& nums, int n, int reqSum,
               int sum, vector<int>& ds) {
    // base case
    if (i == n) {
        if (sum == reqSum) {
            // return ds
            for (int x : ds) cout << x << " ";
            cout << endl;
            return true; // ✅ stop once one subsequence is found
        }
        return false;
    }

    // TAKE current element
    ds.push_back(nums[i]);
    if (recursion(i+1, nums, n, reqSum, sum + nums[i], ds)) return true;
    ds.pop_back(); // backtrack

    // NOT TAKE current element
    if (recursion(i+1, nums, n, reqSum, sum, ds)) return true;

    return false; // no valid subsequence found
}




// count all subsequences whose sum equals reqSum
// TC: O(2n)
// SC: O(N)
int recursion(int i, vector<int>& nums, int n, int reqSum,
              int sum) {
    // base case
    if (i == n) {
        if (sum == reqSum) return 1;  // valid subsequence found
        return 0;                     // not valid
    }

    // pick element
    int left = recursion(i+1, nums, n, reqSum, sum + nums[i]);

    // not pick element
    int right = recursion(i+1, nums, n, reqSum, sum);

    return left + right;  // total count
}
