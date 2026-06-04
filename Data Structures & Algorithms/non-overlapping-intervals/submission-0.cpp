class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(), [](const vector<int> &a, const vector<int>&b){
             return a[1]<b[1];
        });

        int end_time=intervals[0][1];
        int remove_count=0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<end_time){
                remove_count++;
            }
            else{
                end_time=intervals[i][1];
            }
        }
        return remove_count;
    }
};
