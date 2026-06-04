class Solution {
public:

    int solve(vector<vector<int>>& grid, int row, int col,vector<vector<int>>&dp){
        int n=grid.size();
        int m=grid[0].size();

        if(row>=n || col>=m){
            return 1e9;
        }
        if(row==n-1 && col==m-1){
            return grid[row][col];
        }

        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int down=solve(grid,row+1,col,dp);
        int right=solve(grid,row,col+1,dp);

        return dp[row][col]=grid[row][col] + min(down,right);

    }
    int minPathSum(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        
       int ans= solve(grid,0,0,dp);
       return ans;
    }
};