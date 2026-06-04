class Solution {
public:
int helper(string &s, int left,int right){
    int count=0;
    while(left>=0 && right<s.size() && s[left]==s[right]){
        count++;
        left--;
        right++;
    }
    return count;
}
    int countSubstrings(string s) {
        int total_count=0;
        for(int i=0;i<s.length();i++){
        total_count+=helper(s,i,i);
        total_count+=helper(s,i,i+1);
        }
        return total_count;
    }
};
