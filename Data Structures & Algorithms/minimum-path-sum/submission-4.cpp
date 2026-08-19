class Solution {
public:
int solve(vector<vector<int>>& grid,int row, int col,vector<vector<int>>&dp){
  int n=grid.size();
  int m=grid[0].size();
  if(row >=n || col >=m){
    return INT_MAX;
  }
  if(row==n-1 && col==m-1){
    return grid[row][col];
  }
  if(dp[row][col]!=-1){
    return dp[row][col];
  }
  int right=solve(grid,row,col+1,dp);
  int down=solve(grid,row+1,col,dp);
  return dp[row][col]=grid[row][col]+min(right,down);

}
    int minPathSum(vector<vector<int>>& grid) {
      int n=grid.size();
  int m=grid[0].size();
  vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(grid,0,0,dp);

    }
};