class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        int rem_cap=capacity-trips[0][0];
        for(int i=1;i<n;i++){
           if(trips[i][1]>=trips[i-1][2]){
            if(trips[i][0]<=capacity){
            return true;
            }
           }
           else{
              rem_cap-=trips[i][0];
              if(rem_cap>=0){
                return true;
              }
           }
        }
        return false;
    }
};