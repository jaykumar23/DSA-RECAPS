// TC: Worst case = O(4^(n*n)) 4 directions
// SC: O(n^2)

class Solution {
  public:
    void solve(int i, int j,string move, vector<vector<int>>& maze,vector<vector<int>> &visited
    ,vector<string>& ans, int n){
        // base condition
        if(i==n-1 && j==n-1){
            ans.push_back(move);
            return;
        }
        
        // downward
        if(i+1<n && !visited[i+1][j] && maze[i+1][j] == 1){
            visited[i+1][j] = 1;
            solve(i+1, j, move+'D', maze, visited, ans, n);
            visited[i+1][j] = 0; // backtrack
        }
        
        // left
        if(j-1>=0 && !visited[i][j-1] && maze[i][j-1] == 1){
            visited[i][j-1] = 1;
            solve(i, j-1, move+'L', maze, visited, ans, n);
            visited[i][j-1] = 0; // backtrack
        }
        
        // right
        if(j+1<n && !visited[i][j+1] && maze[i][j+1] == 1){
            visited[i][j+1] = 1;
            solve(i, j+1, move+'R', maze, visited, ans, n);
            visited[i][j+1] = 0; // backtrack
        }
        
        // up
        if(i-1>=0 && !visited[i-1][j] && maze[i-1][j] == 1){
            visited[i-1][j] = 1;
            solve(i-1, j, move+'U', maze, visited, ans, n);
            visited[i-1][j] = 0; // backtrack
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        int n = maze.size();
        vector<vector<int>> visited(n, vector<int>(n,0));
        if(maze[0][0] == 1) {
            // mark first cell visited
            visited[0][0] = 1;
            solve(0, 0, "", maze, visited, ans, n);
        }
        return ans;
    }
};
