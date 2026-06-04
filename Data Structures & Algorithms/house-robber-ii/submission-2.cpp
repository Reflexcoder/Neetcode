class Solution {
public:
int rob2(vector<int>&nums,int start,int end){
    

int prev1=0;
int prev2=0;
   for(int i=start;i<=end;i++){
    int current = max( prev2, prev1 + nums[i]);
   prev1=prev2;
   prev2=current;
   }
   return prev2;
}


    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        int a= rob2(nums,0,n-2);
        int b=rob2(nums,1,n-1);
        return max(a,b);
    }
};
