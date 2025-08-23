// TC: O(4^n x n)
// SC: O(n)

class Solution {
public:
    void backTrack(int i, string& digits, vector<string>&ans, string& temp, unordered_map<char, string> &m){
        // base case
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }

        string letters = m[digits[i]];
        for(char c: letters){
            temp.push_back(c); // pick
            backTrack(i+1, digits, ans, temp, m); // explore
            temp.pop_back(); // undo
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        vector<string> ans;
        string temp;

        // edge case
        if (digits.empty()) return ans;

        backTrack(0, digits, ans, temp, m);
        return ans;
    }
};
