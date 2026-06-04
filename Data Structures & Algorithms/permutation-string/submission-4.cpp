class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        unordered_map<char,int>map1;
        unordered_map<char,int>map2;
        if(n>m){
            return false;
        }
        for(int i=0;i<n;i++){
            map1[s1[i]]++;
            map2[s2[i]]++;
        }
        
        if(map1==map2){
            return true;
        }
        for(int i=n;i<m;i++){
            char newchar = s2[i];
            char oldchar= s2[i-n];
            
        
        if(map2[oldchar]==1){
            map2.erase(oldchar);
        }else{
            map2[oldchar]--;
        }
        
        map2[newchar]++;
        if(map1==map2){
            return true;
        }

        
    }
    return false;
    }
    
};
