class Solution {
public:

    void backtrack(vector<int>&nums, vector<int>&bucket, vector<vector<int>>&ans,vector<bool>&used){
        if(bucket.size()==nums.size()){
            ans.push_back(bucket);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==true){
                continue;
            }
            bucket.push_back(nums[i]);
            used[i]=true;
            backtrack(nums,bucket,ans,used);
            bucket.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>bucket;
        vector<vector<int>>ans;
        vector<bool>used(nums.size(),false);
        backtrack(nums,bucket,ans,used);
        return ans;
    }
};
