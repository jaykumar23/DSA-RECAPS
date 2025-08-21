class Solution {
public:
    void backTrack(int open, int close, string s, int n, vector<string> &ans){
        // base condition - see the o/p each has 2n characters
        if(open+close >= 2*n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            backTrack(open+1, close, s+"(", n , ans);
        }
        // open & close should match
        if(close < open){
            backTrack(open, close+1, s+")", n, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> ans;
        backTrack(0,0,s, n, ans);
        return ans;
    }
};
