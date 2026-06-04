class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0;
        int right=0;
        int longest=0;
        unordered_map<int,int>map;
        while(right<n){
           if(map.find(s[right])!=map.end()){
                      left=max(left,map[s[right]]+1);
                      
           }
           longest=max(longest,right-left+1);
           map[s[right]]=right;
           right++;
        }
        return longest;
    }
};
