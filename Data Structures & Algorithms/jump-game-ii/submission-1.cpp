class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jump=0;
        int farest=0;
        int local_max=0;
        for(int i=0;i<n-1;i++){
          farest=max(farest,i + nums[i]);
          if(i == local_max){
            jump++;
            local_max=farest;
          }
          if(local_max>n-1){
            break;
          }
        }
        return jump;
    }
};
