class Solution {
public:
    int solve(vector<int>&nums, int remTarget,int index){
        if(index==nums.size()){
           if(remTarget==0){
            return 1;
           }
           else{
            return 0;
           }
        }
       
        int take_plus=solve(nums,remTarget-nums[index],index+1);
        int take_minus=solve(nums,remTarget+nums[index],index+1);
        return take_plus + take_minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int ans= solve(nums,target,0);
        return ans;
    }
};