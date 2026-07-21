class Solution {
public:
int solve(vector<int>&cost,int n){
    
     if(n==0){
        return 0;
     }
     if(n==1){
        return 0;
     }
     
     return min(cost[n-1] + solve(cost,n-1),cost[n-2]+solve(cost,n-2));

}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int ans=solve(cost,n);
        return ans;
    }
};
