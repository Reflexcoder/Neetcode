class Solution {
public:
int solve(vector<int>&coins,int remAmount,vector<int>&dp){
  if(remAmount==0){
    return 0;
  }
  if(remAmount<0){
    return INT_MAX;
  }
  if(dp[remAmount]!=-1){
    return dp[remAmount];
  }
  int minCoins=INT_MAX;
  for(auto &coin : coins){
    int numberCoins=solve(coins,remAmount-coin,dp);
    if(numberCoins!=INT_MAX){
      minCoins=min(minCoins,numberCoins+1);
    }
  }
  return dp[remAmount]=minCoins;
}
    int coinChange(vector<int>& coins, int amount) {
      vector<int>dp(amount+1,-1);
        int ans=solve(coins,amount,dp);
        
        if(ans==INT_MAX){
          return -1;
        }
        return ans;
    }
};
