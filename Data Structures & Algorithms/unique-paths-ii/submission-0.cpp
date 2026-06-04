class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,int row,int col,vector<vector<int>>&dp){
         int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
          

        if (row >= n || col >= m) {
            return 0;
        }

        

        if(obstacleGrid[row][col]==1){
            return 0;
        }
        if(row==n-1 && col==m-1){
            return 1;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int down=solve(obstacleGrid,row+1,col,dp);
        int right=solve(obstacleGrid,row,col+1,dp);

        return dp[row][col]=down + right;



    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
       int ans= solve(obstacleGrid,0,0,dp);
       return ans;
    }
};