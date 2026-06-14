class Solution {
public:
    int solve(string &s,int index){
        int n=s.size();
        if(index==n){
            return 1;
        }
        if(s[index]=='0'){
            return 0;
        }
        int ways=0;
        ways+=solve(s,index+1);
     
        if(index+1<n){
            int two=(s[index]-'0')*10 + (s[index+1]-'0');
            if(two>=10 && two<=26){
                ways+=solve(s,index+2);
            }
        }
        return ways;

    }
    int numDecodings(string s) {
        //unordered_map<int,int>mapp;
        return solve(s,0);
        
    }
};
