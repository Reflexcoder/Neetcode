class Solution {
public:

     int solve(int remAmount,vector<int>&coins,  int index, vector<vector<int>>&dp){
        if(remAmount==0){
            return 1;
        }
        if(remAmount<0 || index>=coins.size()){
            return 0;
        }
        if(dp[index][remAmount]!=-1){
            return dp[index][remAmount];
        }
        int take=solve(remAmount-coins[index],coins,index,dp);
        int skip=solve(remAmount,coins,index+1,dp);

        return dp[index][remAmount]=skip + take;
     }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(amount,coins,0,dp);
        return ans;

    }
};
