class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int left=0;
        
        int current_sum=0;
        int minCount=INT_MAX;
       for(int right=0;right<n;right++){
        current_sum+=nums[right];
        while(current_sum>=target){
            minCount=min(minCount,right-left+1);
            current_sum-=nums[left];
            left++;
        }
       }
       if(minCount==INT_MAX){
        return 0;
       }
       return minCount;
    }
};