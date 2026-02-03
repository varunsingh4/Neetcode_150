class Solution {
public:
    int maxProfit(vector<int>& prices) {  
        //max profit happens when the prices which we are selling the stock is the lowest number then only the profit will be max and the profit which we will be getting will be max
        int n = prices.size();
        int left=0;
        int max_Profit=INT_MIN;
        int min_prices=INT_MAX;

        for(int i=0;i<prices.size();i++)
        {
            min_prices=min(min_prices,prices[i]);
            max_Profit=max(max_Profit,prices[i]-min_prices);

        }
        return max_Profit;
    }
};
