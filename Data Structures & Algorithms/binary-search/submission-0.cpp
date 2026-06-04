class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        while(i<=j){
            int mid= i + (j-i)/2;
            if(target>nums[mid]){
                i=mid+1;
            }
            else if(target<nums[mid]){
                j=mid-1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};
