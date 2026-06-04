class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int max_so_far=nums[0];
        int min_so_far=nums[0];
        int result=nums[0];
        for(int i=1;i<n;i++){
            int curr=nums[i];
            int temp=max({curr,max_so_far*curr,min_so_far*curr});
            min_so_far=min({curr,min_so_far*curr,max_so_far*curr});
            max_so_far=temp;
            result=max(result,max_so_far);
        }
        return result;
    }
};
