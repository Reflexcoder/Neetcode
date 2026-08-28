class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int max_reach=0;
        int local_reach=0;
        int jump=0;
        for(int i=0;i<n;i++){
            max_reach=max(max_reach,nums[i] + i);
            if(i==local_reach){
                jump++;
                local_reach=max_reach;
            }
            if(max_reach>=n){
                break;
            }
        }
        return jump;
    }
};
