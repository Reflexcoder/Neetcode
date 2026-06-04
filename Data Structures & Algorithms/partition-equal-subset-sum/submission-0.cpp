class Solution {
public:
    bool solve(vector<int>&nums,int remTarget,int index, vector<vector<int>>&dp){
 
            if(remTarget==0){
                return true;
            }


            if(index>=nums.size() || remTarget<0){
                return false;
            }
            if(dp[index][remTarget]!=-1){
                return dp[index][remTarget];
            }
            
            bool take=solve(nums,remTarget-nums[index],index+1,dp);
            bool skip =solve(nums,remTarget,index+1,dp);

            return dp[index][remTarget]=take || skip; 
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total_sum=0;
        
        for(int i=0;i<n;i++){
            total_sum+=nums[i];
        }
        if(total_sum%2 == 0){
            int target=total_sum/2;
            vector<vector<int>>dp(n,vector<int>(target+1,-1));
            return solve(nums,target,0,dp);
        }
       
       return false;
        
    }
};
