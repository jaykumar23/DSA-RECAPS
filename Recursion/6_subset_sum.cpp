// https://www.geeksforgeeks.org/problems/subset-sums2234/1&selectedLang=python3
// TC: O(2^n)
// SC: O(2^n) w o/p

class Solution {
  public:
    void recursion(int i, int sum, vector<int>& arr, vector<int>&ans){
        if(i==arr.size()){
            ans.push_back(sum);
            return;
        }
        
        // pick
        recursion(i+1, sum+arr[i], arr, ans);
        
        // not pick
        recursion(i+1, sum, arr, ans);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> ans;
        recursion(0, 0, arr, ans);
        return ans;
    }
};
