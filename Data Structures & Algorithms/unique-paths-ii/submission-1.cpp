class Solution {
public:
int solve(vector<vector<int>>& obstacleGrid,int row,int col,vector<vector<int>>&dp){
  int n=obstacleGrid.size();
  int m=obstacleGrid[0].size();
  if(row<0 || row>=n || col<0 || col>=m || obstacleGrid[row][col]==1){
    return 0;
  }
  if(row==n-1 && col==m-1){
    return 1;
  }
  if(dp[row][col]!=-1){
    return dp[row][col];
  }
  int take_right=solve(obstacleGrid,row,col+1,dp);
  int take_down=solve(obstacleGrid,row+1,col,dp);
  return dp[row][col]=take_right+take_down;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int n=obstacleGrid.size();
  int m=obstacleGrid[0].size();
      vector<vector<int>>dp(n,vector<int>(m,-1));
      return solve(obstacleGrid, 0,0,dp); 
    }
};