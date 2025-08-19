// Recursive
// Time: O(2^n)
// Space: O(n) (recursion depth)

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

// Memoization
// Time: O(n)
// Space: O(n) (dp + recursion stack)

class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n <= 1) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};


// Tabulation
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};


// Space Optimized
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;

        int prev2 = 1; // f(0)
        int prev1 = 1; // f(1)

        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
