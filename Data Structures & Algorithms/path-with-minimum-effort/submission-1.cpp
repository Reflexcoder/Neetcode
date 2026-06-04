class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>track(n,vector<int>(m,INT_MAX));
        track[0][0]=0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int effort=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1 && col==m-1){
                return effort;
            }

            for(int i=0;i<4;i++){
               int rnew=row + dr[i];
               int cnew=col + dc[i];
            

            

            if(rnew>=0 && rnew<n && cnew>=0 && cnew<m ){
                int jump_effort=abs(heights[rnew][cnew] -heights[row][col]);
                int max_effort=max(effort,jump_effort);

                if(max_effort<track[rnew][cnew]){
                    track[rnew][cnew]=max_effort;
                    pq.push({max_effort,{rnew,cnew}});
                }
            
            }
            }
            
        }
          return 0;
    }
};