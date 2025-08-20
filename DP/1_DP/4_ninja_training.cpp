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
