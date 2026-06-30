class Solution {
public:
int solve(vector<vector<int>>& triangle,int row, int col,vector<vector<int>>&dp){
    int n=triangle.size();
    
         if(row==n){
            return 0;
         }
         if(dp[row][col]!=INT_MIN){
             return dp[row][col];
         }
         int takefirst=triangle[row][col]+solve(triangle,row+1,col,dp);
         int takesecond=triangle[row][col]+solve(triangle,row+1,col+1,dp);
         return dp[row][col]=min(takefirst,takesecond);

}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
       int ans= solve(triangle, 0,0,dp);
       return ans;
    }
};