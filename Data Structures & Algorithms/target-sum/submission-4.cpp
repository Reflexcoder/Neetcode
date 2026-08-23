class Solution {
public:
int solve(vector<int>&nums,int remAmount,int index,vector<vector<int>>&dp,int &total){
  if(index==nums.size()){
    if(remAmount==0){
      return 1;
    }
    else{
      return 0;
    }
  }
  if (remAmount + total < 0 || remAmount + total > 2*total)
            return 0;

  if (dp[index][remAmount + total] != -1)
    return dp[index][remAmount + total];
  int take_plus=solve(nums,remAmount-nums[index],index+1,dp,total);
  int take_minus=solve(nums,remAmount+nums[index],index+1,dp,total);

  return dp[index][remAmount + total] = take_plus + take_minus;
}
    int findTargetSumWays(vector<int>& nums, int target) {
      int n=nums.size();
      int total=0;
      for(auto it : nums){
        total+=it;
      }
      vector<vector<int>>dp(n,vector<int>(2*total+1,-1));
       int ans=solve(nums,target,0,dp,total);
       return ans;
    }
};
