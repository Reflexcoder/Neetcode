class Solution {
public:

  void backtrack(vector<int>&ans,vector<vector<int>>&result,int index,vector<int>&nums){
    if(index==nums.size()){
        result.push_back(ans);
        return;
    }
    ans.push_back(nums[index]);
    backtrack(ans,result,index+1,nums);
    ans.pop_back();
    backtrack(ans,result,index+1,nums);

  }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>result;
        backtrack(ans,result,0,nums);
        return result;
    }
};
