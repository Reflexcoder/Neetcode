class Solution {
public:
int solve(vector<int>&nums,int remAmount,int index){
  if(index==nums.size()){
    if(remAmount==0){
      return 1;
    }
    else{
      return 0;
    }
  }
  int take_plus=solve(nums,remAmount-nums[index],index+1);
  int take_minus=solve(nums,remAmount+nums[index],index+1);

  return take_plus + take_minus;
}
    int findTargetSumWays(vector<int>& nums, int target) {
       return solve(nums,target,0);
    }
};
