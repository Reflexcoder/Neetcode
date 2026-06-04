class Solution {
public:

    void backtrack(vector<int>&nums,int rem_target, int index,vector<int>&bucket,vector<vector<int>>&ans){
        if(rem_target==0){
            ans.push_back(bucket);
            return;
        }
        if(rem_target<0 || index==nums.size()){
            return;
        }
        bucket.push_back(nums[index]);
        backtrack(nums,rem_target-nums[index],index,bucket,ans);
        bucket.pop_back();
        backtrack(nums,rem_target,index+1,bucket,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>bucket;
        vector<vector<int>>ans;
        backtrack(nums,target,0,bucket,ans);
        return ans;
    }
};
