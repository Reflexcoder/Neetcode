class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int s=times.size();
        vector<vector<pair<int,int>>>adj(n+1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto &time : times){
            int u=time[0];
            int v=time[1];
            int w=time[2];
            adj[u].push_back({v,w});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int time=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            



            for(auto &neighbour: adj[u]){
                int v=neighbour.first;
                int vtime=neighbour.second;
                if(dist[u]+ vtime<dist[v]){
                    dist[v]=dist[u] + vtime;
                    pq.push({dist[v],v});
                }
            }
        }
        int timetaken=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
           timetaken=max(timetaken,dist[i]);
        }
        return timetaken;
    }
};
