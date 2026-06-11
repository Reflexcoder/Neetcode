class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        unordered_map<char,int>map1,map2;
        for(int i=0;i<m;i++){
            map2[t[i]]++;
        }
        int left=0;
        int min_len=INT_MAX;
        int needed=map2.size();
        int formed=0;
        int start=0;
        for(int right=0;right<n;right++){
            map1[s[right]]++;
            if(map2.find(s[right])!=map2.end() && map1[s[right]]==map2[s[right]]){
                  formed++;
            }
            while(formed==needed){
                if(min_len>right-left+1){
                    min_len=right-left+1;
                    start=left;
                }
                map1[s[left]]--;
                if(map2.find(s[left])!=map2.end() && map1[s[left]]<map2[s[left]]){
                          formed--;
                }
                left++;
            }
        }
    
            if(min_len==INT_MAX){
                return "";
            }
            
            
          return s.substr(start,min_len);
        }

    
};
