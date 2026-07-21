class Solution {
public:
    int solve(string s, int left, int right, int &max,int &start){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            int current=right-left+1;
             if(current>max){
                max=current;
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
            solve(s,i,i,max,start);
            solve(s,i,i+1,max,start);
        }
        return s.substr(start,max);
    }
};
