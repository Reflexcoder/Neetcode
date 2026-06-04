class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        vector<int>ans;
        for(auto &it : map){
            if(it.second>n/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};