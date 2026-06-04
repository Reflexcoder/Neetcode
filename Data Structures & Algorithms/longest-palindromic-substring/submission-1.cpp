class Solution {
public:

    void helper(string &s, int left, int right, int &start,int &max_length ){
          while(left>=0 && right<s.size() && s[left]==s[right]){
           int current_length=right-left+1;
           if(current_length>max_length){
            max_length=current_length;
            start=left;
           }
           left--;
           right++;
          }
    }

    string longestPalindrome(string s) {
        int n=s.size();
        int max_length=1;
        int start=0;
        for(int i=0;i<n;i++){
        helper(s,i,i,start,max_length);
        helper(s,i,i+1,start,max_length);
        }

        return s.substr(start,max_length);
    }
};
