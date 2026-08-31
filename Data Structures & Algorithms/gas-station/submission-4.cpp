class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_sum=0;
        int cost_sum=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            gas_sum+=gas[i];
            cost_sum+=cost[i];
        }

        if(cost_sum>gas_sum){
            return -1;
        }
        int start=0;
        int current_diff=0;
        for(int i=0;i<n;i++){
            current_diff=gas[i]-cost[i];
            if(current_diff<0){
                start=i+1;
                current_diff=0;
            }
        }
        return start;

    }
};
