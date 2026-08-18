class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int mini=nums[0];
        int maxi=nums[0];
        int global_max=nums[0];
        for(int i=1;i<n;i++){
          int curr=nums[i];
          int temp=min({curr,curr*mini,curr*maxi});
          maxi=max({curr,curr*mini,curr*maxi});
          mini=temp;
          global_max=max(global_max,maxi);
        }
        return global_max;
    }
};
