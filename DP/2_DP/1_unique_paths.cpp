// recursive
// Time: O(2^(m+n)) (exponential, because of overlapping subproblems).
// Space: O(m+n) recursion depth.
class Solution {
public:
    int solve(int x, int y, int m, int n){
        // reached destination
        if(x==m-1 && y==n-1) return 1;
        // out of bounds
        if(x>=m || y>=n) return 0;

        int up = solve(x+1, y, m, n);
        int down = solve(x, y+1, m, n);
        return up+down;
    }
    int uniquePaths(int m, int n) {
     return solve(0,0,m,n);   
    }
};

// memo
// Time: O(m * n) → every state (x,y) is solved once.
// Space: O(m * n) for DP table + O(m+n) recursion depth.
class Solution {
public:
    int solve(int x, int y, int m, int n, vector<vector<int>> dp) {
        // reached destination
        if (x == m - 1 && y == n - 1)
            return 1;
        // out of bounds
        if (x >= m || y >= n)
            return 0;

        if (dp[x][y] != -1) 
            return dp[x][y];
            
        int up = solve(x + 1, y, m, n, dp);
        int down = solve(x, y + 1, m, n,dp);
        return dp[x][y] = up+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp);
    }
};


// tabulation
TC: O(m×n)
SC: O(n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // base case: only 1 way to reach cells in first row & first col
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;

        // fill dp table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};
