class Solution {
public:
int solve(vector<vector<int>>& triangle,int row, int col){
    int n=triangle.size();
    
         if(row==n){
            return 0;
         }
         int takefirst=triangle[row][col]+solve(triangle,row+1,col);
         int takesecond=triangle[row][col]+solve(triangle,row+1,col+1);
         return min(takefirst,takesecond);

}
    int minimumTotal(vector<vector<int>>& triangle) {
       int ans= solve(triangle, 0,0);
       return ans;
    }
};