class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        unordered_map<int,int>map;
        int n=nums.size();
        int max_size=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                map[nums[i]]++;
                max_size=max(max_size,map[1]);
            }
            else{
            
            map[1]=0;
            }
            

        }
        return max_size;
    }
};