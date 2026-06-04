class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &time : times){
             int u=time[0];
             int v=time[1];
             int w=time[2];
             adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int time=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(dist[u]<time){
                continue;
            }
            for(auto &it : adj[u]){
                int v=it.first;
                int vtime=it.second;
                if(dist[u]+vtime<dist[v]){
                    dist[v]=dist[u]+vtime;
                    pq.push({dist[v],v});
                }
            }
        }
        int totaltime=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            totaltime=max(totaltime,dist[i]);
        }
        return totaltime;
    }
};
