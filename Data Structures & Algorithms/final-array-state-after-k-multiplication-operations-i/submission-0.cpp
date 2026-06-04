class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        
        
        for(int i=0;i<n;i++){
            minHeap.push({nums[i],i});
        }

        while(k>0){
            int minimum=minHeap.top().first;
            int index=minHeap.top().second;
            minHeap.pop();
            minHeap.push({minimum*multiplier , index});
            k--;

        }
        vector<int>result(n);
        while(!minHeap.empty()){
            int el=minHeap.top().first;
            int index=minHeap.top().second;
            minHeap.pop();
            result[index]=el;
        }
        return result;
    }
};