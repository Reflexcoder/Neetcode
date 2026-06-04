class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=points.size();
        for(int i=0;i<n;i++){
            int diff=((points[i][0] -  0)*(points[i][0] - 0) + (points[i][1] -0)*(points[i][1] -0));
            pq.push({diff,i});
        }
        vector<vector<int>>result;
        while(k>0){
            int index=pq.top().second;
            pq.pop();
            result.push_back(points[index]);
            k--;

        }
        return result;
    }
};
