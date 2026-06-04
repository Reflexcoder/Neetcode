class Solution {
public:

    bool solve(string &s, int left, int right,vector<vector<int>>&dp){
        if(left>=right){
            return true;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        if(s[left]==s[right]){
            return dp[left][right]=solve(s,left+1,right-1,dp);
        }
        return dp[left][right]=false;
    }

    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int max_length=0;
        int start=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j,dp)){
                    int curr_length=j-i+1;
                    if(curr_length>max_length){
                        max_length=curr_length;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,max_length);
    }
};
