class Solution {
public:
    int solve(vector<int>& prices,int index,bool holding, vector<vector<int>>&dp){
        int n=prices.size();
        if(index>=n){
            return 0;
        }
        if(dp[index][holding]!=-1){
            return dp[index][holding];
        }
        if(!holding){
            int buy= -prices[index] + solve(prices,index+1,1,dp);
            int skip=solve(prices,index+1,0,dp);
            return dp[index][holding]=max(buy, skip);
        }
        else{
            int sell=prices[index] + solve(prices,index+2,0,dp);
            int skip=solve(prices,index+1,1,dp);
            return dp[index][holding]=max(sell,skip);
        }

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(prices,0,0,dp);
    }
};
