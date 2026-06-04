class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int maxlen=0;
        int n=s.size();
        vector<int>map(256,-1);
        while(right<n){
            if(map[s[right]]!=-1){
                left=max(left,map[s[right]]+1);
            }
            maxlen=max(maxlen,right-left+1);
            map[s[right]]=right;
            right++;
        }
        return maxlen;
    }
};
