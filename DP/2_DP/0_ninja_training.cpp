// recursive
// TC: O(3^n)
// SC: O(n)

class Solution {
public:
    int solve(int day, int last, vector<vector<int>>& matrix) {
        // base case: first day
        if (day == 0) {
            int maxi = 0;
            for (int j = 0; j < 3; j++) {
                if (j != last) {
                    maxi = max(maxi, matrix[0][j]);
                }
            }
            return maxi;
        }

        int maxi = 0;
        // try all activities except 'last'
        for (int j = 0; j < 3; j++) {
            if (j != last) {
                int points = matrix[day][j] + solve(day - 1, j, matrix);
                maxi = max(maxi, points);
            }
        }
        return maxi;
    }

    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        return solve(n - 1, 3, matrix); // last=3 means no restriction
    }
};

// memoization 
// TC: O(3^n)
// SC: O(n)

class Solution {
public:
    int solve(int day, int last, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        // check memo
        if (dp[day][last] != -1) return dp[day][last];

        // base case: first day
        if (day == 0) {
            int maxi = 0;
            for (int j = 0; j < 3; j++) {
                if (j != last) {
                    maxi = max(maxi, matrix[0][j]);
                }
            }
            return dp[day][last] = maxi;
        }

        int maxi = 0;
        // try all activities except 'last'
        for (int j = 0; j < 3; j++) {
            if (j != last) {
                int points = matrix[day][j] + solve(day - 1, j, matrix, dp);
                maxi = max(maxi, points);
            }
        }
        return dp[day][last] = maxi;
    }

    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solve(n - 1, 3, matrix, dp); // last=3 means no restriction
    }
};


// tabulation
// O(N)
// O(N)
class Solution {
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));

        // base case: day 0
        dp[0][0] = max(matrix[0][1], matrix[0][2]);
        dp[0][1] = max(matrix[0][0], matrix[0][2]);
        dp[0][2] = max(matrix[0][0], matrix[0][1]);
        dp[0][3] = max({matrix[0][0], matrix[0][1], matrix[0][2]});

        // fill dp table
        for (int day = 1; day < n; day++) {
            for (int last = 0; last < 4; last++) {
                dp[day][last] = 0;
                for (int j = 0; j < 3; j++) {
                    if (j != last) {
                        int points = matrix[day][j] + dp[day-1][j];
                        dp[day][last] = max(dp[day][last], points);
                    }
                }
            }
        }

        return dp[n-1][3]; // no restriction on last activity
    }
};


// tab-opt
// O(N)
// O(1)
class Solution {
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> prev(4, 0), curr(4, 0);

        // base case: day 0
        prev[0] = max(matrix[0][1], matrix[0][2]);
        prev[1] = max(matrix[0][0], matrix[0][2]);
        prev[2] = max(matrix[0][0], matrix[0][1]);
        prev[3] = max({matrix[0][0], matrix[0][1], matrix[0][2]});

        // fill table iteratively
        for (int day = 1; day < n; day++) {
            for (int last = 0; last < 4; last++) {
                curr[last] = 0;
                for (int j = 0; j < 3; j++) {
                    if (j != last) {
                        int points = matrix[day][j] + prev[j];
                        curr[last] = max(curr[last], points);
                    }
                }
            }
            prev = curr; // update for next iteration
        }

        return prev[3]; // no restriction on last day
    }
};
