class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(2*n);
        int m=ans.size();
        for(int i=0;i<n;i++){
            ans[i]=nums[i];
        }
        for(int i=n;i<m;i++){
            ans[i]=nums[i-n];
        }
        return ans;
    }
};