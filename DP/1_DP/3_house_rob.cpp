// recursive
// TC: O(2^n)
// SC: O(n)

class Solution {
public:
int solve(int idx, vector<int>& nums) {
        if (idx == 0) return nums[0];   // first house
        if (idx < 0) return 0;          // no house left

        int pick = nums[idx] + solve(idx - 2, nums);
        int notPick = 0 + solve(idx - 1, nums);

        return max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(n - 1, nums);
    }
};

// memoization
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int solve(int idx, vector<int>& nums, vector<int>& dp) {
        if (idx == 0)
            return nums[0]; // first house
        if (idx < 0)
            return 0; // no house left

        if (dp[idx] != -1)
            return dp[idx]; // already computed

        int pick = nums[idx] + solve(idx - 2, nums, dp);
        int notPick = solve(idx - 1, nums, dp);

        return dp[idx] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n - 1, nums, dp);
    }
};



// tabulation
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev2 = 0;        // dp[i-2]
        int prev1 = nums[0];  // dp[i-1]

        for (int i = 1; i < n; i++) {
            int pick = nums[i];
            if (i > 1) pick += prev2;   // rob current + dp[i-2]

            int notPick = prev1;        // skip current

            int curr = max(pick, notPick);

            prev2 = prev1;              // shift
            prev1 = curr;
        }

        return prev1;
    }
};



//tabulation with opt
TC: O(n)
SC: O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev2 = 0;        // dp[i-2]
        int prev1 = nums[0];  // dp[i-1]

        for (int i = 1; i < n; i++) {
            int pick = nums[i];
            // base case for -ve
            if (i > 1) pick += prev2;   // rob current + dp[i-2]

            int notPick = prev1;        // skip current

            int curr = max(pick, notPick);

            prev2 = prev1;              // shift
            prev1 = curr;
        }

        return prev1;
    }
};



