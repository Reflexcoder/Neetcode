class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>set(nums.begin(),nums.end());
        int maxl=0;
        for(auto it : set){
            if(set.find(it-1)==set.end()){
                int currentel=it;
                int currentlen=1;
            
            while(set.find(currentel+1)!=set.end()){
                currentel++;
                currentlen++;
                
            }
            maxl=max(maxl,currentlen);
            }
            
        
        
        }
        return maxl;

    }
};
