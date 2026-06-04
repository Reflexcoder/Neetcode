class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>map;
        int maxlen=0;
        int left=0;
        int right=0;
        for(int i=0;i<n;i++){
            if(map.find(s[i])!=map.end()){
                left=max(left,map[s[i]]+1);
            }
            maxlen=max(maxlen,right-left+1);
            map[s[i]]=i;
            right++;
        }
        return maxlen;
        
    }
};
