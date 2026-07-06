class Solution {
public:
    int solve( vector<int>&suffix,int index, int M , int n){
        if(index>=n){
            return 0;
        }
        if(index + 2*M >= n){
          
            return suffix[index];
        }
        int best_score=0;
        for(int X=1;X<=2*M;X++){
            int opponent=solve(suffix,index+X,max(M,X),n);
            best_score=max(best_score,suffix[index]-opponent);
        }
        return best_score;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<int>suffix(n);
         suffix[n-1]=piles[n-1];
         for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]  + piles[i];
         }
         
         return solve(suffix,0,1,n);
    }
};