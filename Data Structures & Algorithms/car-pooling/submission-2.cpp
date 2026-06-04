class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        sort(trips.begin(),trips.end() , [](auto &a, auto &b){
            return a[1]<b[1];
        });
        int current=0;
        for(auto trip : trips){
            int pass=trip[0];
            int start=trip[1];
            int end=trip[2];
            while(!pq.empty() && start>=pq.top().first){
                current-=pq.top().second;
                pq.pop();
                
            }

            current+=pass;
            if(current>capacity){
                return false;
            }
            pq.push({end,pass});
        }
        return true;
       }
    
};