class Solution {
public:
    int solve(vector<int>&nums,int start,int end){
        if(end<start){
            return 0;
        }
        if(end==start){
            return nums[start];
        }
        int prev1=0;
        int prev2=0;
       
        for(int i=start;i<=end;i++){
           int current=max(prev1,prev2 + nums[i]);
           prev2=prev1;
           prev1=current;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        
        int houseA=solve(nums,0,n-2);
        int houseB=solve(nums,1,n-1);
        return max(houseA,houseB);
    }
};
