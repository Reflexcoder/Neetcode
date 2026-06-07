class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mapp;
        int pairs=0;
        for(int i=0;i<n;i++){
             if(mapp.find(nums[i])!=mapp.end()){
                  pairs+=mapp[nums[i]];
             }
            mapp[nums[i]]++;
        }
        return pairs;
    }
};