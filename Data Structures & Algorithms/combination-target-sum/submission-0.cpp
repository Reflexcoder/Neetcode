class Solution {
public:
 

    void backtrack(int index,int rem_target, vector<int>&nums,vector<vector<int>>&ans,vector<int>&current_ans){
             if(rem_target==0){
                ans.push_back(current_ans);
                return;
             }
             if(rem_target<0 || index==nums.size()){
                return;
             }

            current_ans.push_back(nums[index]);
            backtrack(index,rem_target-nums[index],nums,ans,current_ans);
            current_ans.pop_back();
            backtrack(index+1,rem_target,nums,ans,current_ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>>ans;
        vector<int>current_ans;
        backtrack(0,target,nums,ans,current_ans);
        return ans;
    }
};
