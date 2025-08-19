// recursive
// Time: O(2^n) (because every stone can branch into 2 recursive calls) → exponential ❌
// Space: O(n) recursion depth.

// class Solution {
// public:
//     int solve(int n, vector<int>& heights){
//         if(n==0) return 0;
//          // jump from n-1
//         int left = solve(n-1, heights) + abs(heights[n] - heights[n-1]);
//         int right = INT_MAX;
//         if (n > 1) {
//             // jump from n-2
//             right = solve(n-2, heights) + abs(heights[n] - heights[n-2]);
//         }
//         return min(left, right);
//     }
//     int frogJump(vector<int>& heights) {
//         int n = heights.size();
//         return solve(n-1, heights); 
//     }
};


// memoization
// Time: O(n) (each state computed once)
// Space: O(n) (dp + recursion stack)

// class Solution {
// public:
//     int solve(int n, vector<int>& heights, vector<int>& dp) {
//         if (n == 0) return 0;

//         if (dp[n] != -1) return dp[n];  // already computed

//         int left = solve(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
//         int right = INT_MAX;
//         if (n > 1) {
//             right = solve(n-2, heights, dp) + abs(heights[n] - heights[n-2]);
//         }

//         return dp[n] = min(left, right);
//     }

//     int frogJump(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> dp(n, -1);
//         return solve(n-1, heights, dp);
//     }
// };


// tabulation
// Time:  O(n)
// Space: O(n)

class Solution {
// public:
//     int frogJump(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> dp(n, 0);

//         dp[0] = 0; // base case

//         for (int i = 1; i < n; i++) {
//             int left = dp[i-1] + abs(heights[i] - heights[i-1]);

//             int right = INT_MAX;
//             if (i > 1) {
//                 right = dp[i-2] + abs(heights[i] - heights[i-2]);
//             }

//             dp[i] = min(left, right);
//         }

//         return dp[n-1];
//     }
// };


// space optimized
// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for (int i = 1; i < n; i++) {
            int left = prev1 + abs(heights[i] - heights[i-1]);

            int right = INT_MAX;
            if (i > 1) {
                right = prev2 + abs(heights[i] - heights[i-2]);
            }

            int curr = min(left, right);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

