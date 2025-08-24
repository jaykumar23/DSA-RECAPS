// TC: O(n * 2^n)
// SC: O(n) recursion + O(2^n * n) output storage

class Solution {
public:
    // Utility function to check if a string is palindrome
    bool isPalindrome(string s){
        string rev = s;
        reverse(rev.begin(), rev.end());
        return rev == s;
    }

    // Backtracking function to generate all palindrome partitions
    void getAllParts(string s, vector<vector<string>> &ans, vector<string> &partitions){
        // base condition: if we have consumed the entire string
        if(s.size() == 0){
            ans.push_back(partitions);  // add current partition to result
            return;
        }

        // try every prefix of the string
        for(int i = 0; i < s.size(); i++){
            string subString = s.substr(0, i+1);  // take prefix [0..i]

            // if the prefix is palindrome, include it in current partition
            if(isPalindrome(subString)){
                partitions.push_back(subString);

                // recurse on the remaining substring [i+1..end]
                getAllParts(s.substr(i+1), ans, partitions);

                // backtrack: remove last added palindrome substring
                partitions.pop_back();
            }
        }
    }

    // Main function
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;    // stores all partitions
        vector<string> partitions;     // stores current partition
        getAllParts(s, ans, partitions);
        return ans;
    }
};
