class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jump=0;
        int local_end=0;
        int farest=0;
       for(int i=0;i<n-1;i++){
        farest=max(farest,i + nums[i]);
        if(i==local_end){
          jump++;
          local_end=farest;
        }
        if(local_end>=n){
          break;
        }
       }
       return jump;
    }
};
