class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int total_water=0;
        int left_max=height[left];
        int right_max=height[right];
        while(left<right){
            if(right_max<left_max){
                right--;
                right_max=max(right_max,height[right]);
                total_water+=right_max-height[right];
            }
            else{
                left++;
                left_max=max(left_max,height[left]);
                total_water+=left_max-height[left];
            }
        }
        return total_water;
    }
};
