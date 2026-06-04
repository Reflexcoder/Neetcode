class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &flight: flights){
            int u=flight[0];
            int v=flight[1];
            int w=flight[2];
            adj[u].push_back({v,w});
                    }
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
            pq.push({0,{src,0}});
            vector<int>minStop(n,INT_MAX);
            

            while(!pq.empty()){
                int price=pq.top().first;
                int u=pq.top().second.first;
                int stops=pq.top().second.second;
                pq.pop();
                if(u==dst){
                    return price;
                }
                if(stops>k || stops>=minStop[u]){
                    continue;
                }
                minStop[u]=stops;
                for(auto &it: adj[u]){
                    int vprice=it.second;
                    int v=it.first;
                    pq.push({price+vprice,{v,stops+1}});
                }
                

              
            }
            return -1;
    }
};
