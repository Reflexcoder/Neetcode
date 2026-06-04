class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
       
        int minfreq=INT_MAX;
        int left=0;
        int w_count=0;
        
        
        for(int right=0;right<n;right++){
            if(blocks[right]=='W'){
                w_count++;
            }
           if(right-left+1==k){
            minfreq=min(minfreq,w_count);
            
            if(blocks[left]=='W'){
                w_count--;
            }
            left++;
            
           }

           
           

        }
        return minfreq;
    }
};