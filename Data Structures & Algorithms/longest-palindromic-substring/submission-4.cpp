class Solution {
public:
    bool solve(string &s, int start, int end,vector<vector<int>>&dp){
        if(start>=end){
            return true;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        if(s[start]==s[end]){
            return dp[start][end]=solve(s,start+1,end-1,dp);
        }
        return dp[start][end]=false;
    }
     
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int current=0;
        int max=0;
        int start=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j,dp)){
                    current=j-i+1;
                    if(current>=max){
                        max=current;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,max);
    }
};
