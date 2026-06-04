class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=nums[0];
        int mini=nums[0];
        int global_max=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            int curr=nums[i];
            int temp=min({curr,curr*mini,curr*maxi});
            maxi=max({curr,curr*mini,curr*maxi});
            mini = temp;
            global_max=max(maxi,global_max);
        }
        return global_max;
    }
};
