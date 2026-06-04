class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy_price=prices[0];
        int maxProfit=0;
        for(int i=1;i<n;i++){
            
            if(prices[i]<buy_price){
                buy_price=prices[i];

            }
            else{
                int current_profit=prices[i]-buy_price;
                maxProfit=max(maxProfit,current_profit);
            }
            
        }
        return maxProfit;
    }
};
