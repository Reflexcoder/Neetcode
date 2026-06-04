class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int maxArea=0;
        int left=0;
        int right=n-1;
        while(left<right){
            int currentMin=min(heights[left],heights[right]);
            int width=right-left;
            int currentArea=currentMin*width;
            maxArea=max(maxArea,currentArea);
            if(heights[left]<heights[right]){
                  left++;
            }
            else{
                right--;
            }
        }
        return maxArea;
    }
};
