class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        for(int j=0;j<m;j++){
            mpp[t[j]]--;
        }

        for(auto it : mpp){
            if(it.second != 0){
                return false;
            }
        }
        return true;
    }
};
