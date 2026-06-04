class Solution {
public:

    int solve(vector<int>& stones,int index, int curr_sum,int target,vector<vector<int>>&dp){
        if(index==stones.size()){
            return 0;
        }
        if(dp[index][curr_sum]!=-1){
            return dp[index][curr_sum];
        }
        int skip=solve(stones,index + 1, curr_sum,target,dp);
        int take=0;
        if(curr_sum  +  stones[index]<=target){
            take=stones[index] + solve(stones,index+1,curr_sum + stones[index],target,dp);
        }
        return dp[index][curr_sum]=max(skip,take);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int tot_sum=0;
        
        for( auto it : stones){
            tot_sum+=it;
        }
        int target=tot_sum/2;

        vector<vector<int>>dp(n,vector<int>(target+1,-1));

        int subsetA=solve(stones,0,0,target,dp);
        int subsetB=tot_sum-subsetA;
        return abs(subsetA-subsetB);
    }
};