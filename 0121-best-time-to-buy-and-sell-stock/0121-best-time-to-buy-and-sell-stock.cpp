class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        int buy=prices[0];
        for(int i=1;i<n;i++){
            if(buy>prices[i]){
               buy=prices[i];
            } else {
                profit=max(profit,prices[i]-buy);
            }
        }
        return profit;
    }
};