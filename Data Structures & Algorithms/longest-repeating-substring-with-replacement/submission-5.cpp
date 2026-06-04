class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int left=0;
        int right=0;
        int maxlen=0;
        int maxfreq=0;
        unordered_map<char,int>map;
        while(right<n){
             map[s[right]]++;
        
        maxfreq=max(maxfreq,map[s[right]]);
        if((right-left+1)-maxfreq >k){
            map[s[left]]--;
            left++;
        }
        maxlen=max(maxlen,right-left+1);
        right++;
        }
        return maxlen;

    }
};
