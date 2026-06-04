class Solution {
public:

    int dfs(vector<vector<int>>&grid, int n, int m){
        if(n<0  || n>=grid.size() || m<0 || m>=grid[0].size() || grid[n][m]==0){
            return 0;
        }
        grid[n][m]=0;
        int land=1;
        land+=dfs(grid,n+1,m);
        land+=dfs(grid,n-1,m);
        land+=dfs(grid,n,m+1);
        land+=dfs(grid,n,m-1);
        return land;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int land=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int temp=dfs(grid,i,j);
                    land=max(land,temp);
                }
            }
        }
        return land;
    }
};
