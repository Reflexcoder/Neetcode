class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        if(k==n){
            return arr;
        }
            

        int left=0;
        int right=n-1;
        while(left<right){
            int mid=left + (right-left)/2;
            if(arr[mid]<x){
                left = mid + 1;
            }
            else{
                right=mid;
            }
        }
        int r=left;
        int l=left-1;

        while(k>0){
            if(l<0){
                r++;
            }
            else if(r>=n){
                l--;
            }
            else if(abs(arr[l]-x)<=abs(arr[r]-x)){
                l--;
            }
            else{
                r++;
            }
            k--;
        }
        vector<int>ans;
        for(int i=l+1;i<r;i++){
              ans.push_back(arr[i]);
        }
        return ans;
    }
};

