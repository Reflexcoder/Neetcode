class Solution {
public:

    int solve(vector<int>&piles,int left, int right,vector<vector<int>>&dp){
        if(left>right){
            return 0;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        int take_left=piles[left] - solve(piles,left+1,right,dp);
        int take_right=piles[right] - solve(piles,left,right-1,dp);
        return dp[left][right]=max(take_left,take_right);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(piles,0,n-1,dp)>0;
    }
};