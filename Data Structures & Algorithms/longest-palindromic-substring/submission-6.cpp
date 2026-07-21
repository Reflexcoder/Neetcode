class Solution {
public:
    void solve(string s, int left, int right, int &maxi,int &start){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            int current=right-left+1;
             if(current>maxi){
                maxi=current;
                  start=left;
             }
            
             left--;
             right++;
        }
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0;
        int maxi=1;
        for(int i=0;i<n;i++){
            solve(s,i,i,maxi,start);
            solve(s,i,i+1,maxi,start);
        }
        return s.substr(start,maxi);
    }
};
