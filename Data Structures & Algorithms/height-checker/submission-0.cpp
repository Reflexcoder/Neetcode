class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        vector<int> another;
        for(int i=0;i<n;i++){
            another.push_back(heights[i]);
        }
        sort(another.begin(),another.end());
        int count =0;
        for(int i=0;i<n;i++){
            if(another[i]!=heights[i]){
                count++;
            }
        }
        return count;
    }
};