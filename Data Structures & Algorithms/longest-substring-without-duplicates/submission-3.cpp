class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>map;
        int left=0;
        int right=0;
        int maxlong=0;
        while(right<n){
            if(map.find(s[right])!=map.end()){
                left=max(left, map[s[right]]+1);
            }
            maxlong=max(maxlong,right-left+1);
            map[s[right]]=right;
            right++;
        }
        return maxlong;
    }
};
