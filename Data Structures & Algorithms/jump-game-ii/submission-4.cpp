class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jump=0;
        int localReach=0;
        int maxReach=0;
        for(int i=0;i<n-1;i++){
            maxReach=max(maxReach, nums[i] + i);
            if(i==localReach){
                jump++;
               localReach= maxReach;
            }
            if(localReach>=n-1){
                break;
            }

        }
        return jump;
    }
};
