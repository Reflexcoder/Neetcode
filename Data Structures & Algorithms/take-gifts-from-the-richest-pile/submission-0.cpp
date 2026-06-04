class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n=gifts.size();
        priority_queue<int>maxHeap;
        for(auto it : gifts){
            maxHeap.push(it);
        }
        
        for(int i=0;i<k;i++){
            int max_el=maxHeap.top();
            maxHeap.pop();
            int new_num=sqrt(max_el);
            
            maxHeap.push(new_num);
            
        }
        int sum=0;
        while(!maxHeap.empty()){
            sum+=maxHeap.top();
            maxHeap.pop();
        }
        return sum;
    }
};

