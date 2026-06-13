class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        unordered_map<char,int>mapp1,mapp2;
        for(int i=0;i<m;i++){
            mapp1[t[i]]++;
        }
        int needed=mapp1.size();
        int formed=0;
        int left=0;
        int min_length=INT_MAX;
        int start=0;
        for(int right=0;right<n;right++){
            mapp2[s[right]]++;
            if(mapp1.find(s[right])!=mapp1.end() && mapp1[s[right]]==mapp2[s[right]]){
                formed++;
            }
            while(formed==needed){
                if(min_length>right-left+1){
                    min_length=right-left+1;
                    start=left;
                }
                mapp2[s[left]]--;
                
                if(mapp1.find(s[left])!=mapp1.end() && mapp1[s[left]]>mapp2[s[left]]){
                    formed--;
                }
                left++;
            }
        }
        if(min_length==INT_MAX){
            return "";
        }
        return s.substr(start,min_length);
    }
};
