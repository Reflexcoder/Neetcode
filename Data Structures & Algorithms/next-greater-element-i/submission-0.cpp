class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack<int>st;
        unordered_map<int,int>mapp;
        for(int i=0;i<n;i++){
             while(!st.empty() && st.top() < nums2[i]){
                mapp[st.top()]=nums2[i];
                st.pop();
             }

             st.push(nums2[i]);
        }
         vector<int>ans;
        
        for(int i=0;i<nums1.size();i++){
            if(mapp.find(nums1[i])!=mapp.end()){
                ans.push_back(mapp[nums1[i]]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};