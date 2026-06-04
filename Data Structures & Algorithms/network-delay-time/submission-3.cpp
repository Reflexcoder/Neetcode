class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &time : times){
            adj[time[0]].push_back({time[1],time[2]});
        }
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int time=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(time>dist[u]){
                continue;
            }
            for(auto &it:adj[u]){
                int v=it.first;
                int vtime=it.second;
                if(dist[v]>vtime + dist[u]){
                    dist[v]=vtime + time;
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
