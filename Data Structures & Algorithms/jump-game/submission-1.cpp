class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxLevel=0;
        for(int i=0;i<n;i++){
           if(i>maxLevel){
            return false;
           }
           maxLevel=max(maxLevel,i + nums[i]);
        }
        return true;
    }
};
