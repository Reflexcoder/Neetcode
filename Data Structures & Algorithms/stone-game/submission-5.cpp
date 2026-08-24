class Solution {
public:
    int solve(vector<int>&piles,int left,int right){
        int n=piles.size();
        if(left>right){
            return 0;
        }
        int take_left=piles[left] -solve(piles,left+1,right);
        int take_right=piles[right]-solve(piles,left,right-1);
        return max(take_left,take_right);
        
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        return solve(piles,0,n-1)>0;
    }
};