class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<vector<int>>newtask(n);
        for(int i=0;i<n;i++){
            newtask[i]={tasks[i][0],tasks[i][1],i};
        }
        sort(newtask.begin(),newtask.end());
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        long long time=0;
        int i=0;
        while(ans.size()<n){

             while(i<n && newtask[i][0]<=time){
                pq.push({newtask[i][1],newtask[i][2]});
                i++;
            }


            if(pq.empty()){
                time=newtask[i][0];
                continue;
            }
           
            int protime=pq.top().first;
            int index=pq.top().second;
            pq.pop();
            time+=protime;
            ans.push_back(index);
            
        }
        return ans;


    }
};