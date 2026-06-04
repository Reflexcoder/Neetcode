class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0){
            return false;
        }
        map<int,int>mapp;
        for(int i=0;i<n;i++){
            mapp[hand[i]]++;
        }

        for(auto &it : mapp){
            int candidate=it.first;
            int count=it.second;
            if(count>0){
                for(int i=1;i<groupSize;i++){
                    int needed=candidate+i;
                   
                        if(mapp[needed]<count){
                            return false;
                        }
                        mapp[needed]-=count;
                    
                }
                
        }
        }
        return true;
    }
};
