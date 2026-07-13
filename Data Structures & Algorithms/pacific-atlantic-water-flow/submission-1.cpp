class Solution {
public:
    void dfs(vector<vector<int>>& heights,vector<vector<int>>&vis,int row,int col){
             int n=heights.size();
             int m=heights[0].size();
             vis[row][col]=1;
             int ndir[]={-1,0,1,0};
             int mdir[]={0,1,0,-1};
             for(int i=0;i<4;i++){
              
              int nrow=row + ndir[i];
              int ncol=col + mdir[i];
             
             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && heights[nrow][ncol] >= heights[row][col]){
                dfs(heights,vis,nrow,ncol);
             }
             }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>visP(n,vector<int>(m,0));
        vector<vector<int>>visA(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            dfs(heights,visP,0,i);
        }
        for(int j=0;j<n;j++){
            dfs(heights,visP,j,0);
        }
        for(int i=0;i<m;i++){
            dfs(heights,visA,n-1,i);
        }
        for(int j=0;j<n;j++){
            dfs(heights,visA,j,m-1);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visP[i][j]==1 && visA[i][j]==1){
                   ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
