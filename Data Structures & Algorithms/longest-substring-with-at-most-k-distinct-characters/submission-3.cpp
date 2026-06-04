class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n=s.size();
        int left=0;
        int right=0;
        int maxlen=0;
        unordered_map<char,int>map;
        while(right<n){
             map[s[right]]++;
             if(map.size()>k){
                map[s[left]]--;
                if(map[s[left]]==0){
                    map.erase(s[left]);
                }
                left++;
                
             }
             maxlen=max(maxlen,right-left+1);
             right++;

        }
        return maxlen;
    }
};
