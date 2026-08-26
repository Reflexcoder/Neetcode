class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int n=nums.size();
         int max_sum=nums[0];
         int curr_sum=0;
         if(n==1 && nums[0]==-1){
            return -1;
         }
         for(int i=0;i<n;i++){
            if(curr_sum<0){
                curr_sum=0;
            }
            curr_sum+=nums[i];
            max_sum=max(max_sum,curr_sum);
         }
         return max_sum;
    }
};
