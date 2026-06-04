class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>set(nums.begin(),nums.end());
        if(nums.empty()){
            return 0;
        }
        int maxlen=0;
        for(int it : set){
            if(set.find(it-1)==set.end()){
               int currentel=it;
               int current_length=1;         
                
               
            while(set.find(currentel+1)!=set.end()){
                  currentel++;
                  current_length++;
                          }
                          maxlen=max(maxlen,current_length);
            }
            
        }
        return maxlen;
    }
    
    
};
