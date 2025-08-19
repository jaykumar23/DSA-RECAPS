// Recursive
// Time: O(k^n) → exponential
// Space: O(n) recursion depth

class Solution {
public:
    int solve(int i, vector<int>& heights, int k) {
        if (i == 0) return 0;

        int minSteps = INT_MAX;

        // try all jumps from 1 to k
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int cost = solve(i - j, heights, k) + abs(heights[i] - heights[i - j]);
                minSteps = min(minSteps, cost);
            }
        }

        return minSteps;
    }

    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        return solve(n - 1, heights, k);
    }
};



// Memoization
// Time: O(n * k)
// Space: O(n) (dp + recursion stack)

class Solution {
public:
    int solve(int i, vector<int>& heights, int k, vector<int>& dp) {
        if (i == 0) return 0;

        if (dp[i] != -1) return dp[i];

        int minSteps = INT_MAX;

        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int cost = solve(i - j, heights, k, dp) + abs(heights[i] - heights[i - j]);
                minSteps = min(minSteps, cost);
            }
        }

        return dp[i] = minSteps;
    }

    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);
        return solve(n - 1, heights, k, dp);
    }
};


// Tabulation
// Time: O(n * k)
// Space: O(n)

class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
                }
            }
        }

        return dp[n - 1];
    }
};


👉 Unlike classic Frog Jump (k=2), here k can be large.
Since each state dp[i] depends on up to k previous states, we cannot reduce to O(1) space easily.
So optimal space = O(n).
