class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        int speed= right;
        while(left<=right){
            int mid=left + (right-left)/2;
            int total_hours=0;
            for(int pile : piles){
                total_hours+=(pile/mid) + (pile%mid!=0);
            }
            if(total_hours<=h){
                speed=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return speed;
    
    }
};
