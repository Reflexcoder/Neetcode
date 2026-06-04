class Solution {
public:

    void solve(string &s, int left , int right,int &start,int &max){
              while(left>=0 && right<s.size() && s[left]==s[right]){
                    int curr=right-left+1;
                    if(curr>max){
                        max=curr;
                        start=left;
                    }
                    left--;
                    right++;
              }
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0;
        int max=1;
        for(int i=0;i<n;i++){
            solve(s,i,i,start,max);
            solve(s,i,i+1,start,max);
        }
        return s.substr(start,max);
    }
};
