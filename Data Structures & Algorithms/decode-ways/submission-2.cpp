class Solution {
public:
    int solve(string &s, int index,unordered_map<int,int>&map1){
        int n=s.size();
      if(index==n){
        return 1;
      }
      if(s[index]=='0'){
        return 0;
      }
      if(map1.find(index)!=map1.end()){
        return map1[index];
      }
      int ways=0;
      ways+=solve(s,index+1,map1);
      if(index+1<n){
        int two=(s[index]-'0')*10 + (s[index+1]-'0');
        if(two>=10 && two<=26){
            ways+=solve(s,index+2,map1);
        }
      }
      return map1[index]=ways;

    }
    int numDecodings(string s) {
        unordered_map<int,int>map1;
       return solve(s,0,map1);
    }
};
