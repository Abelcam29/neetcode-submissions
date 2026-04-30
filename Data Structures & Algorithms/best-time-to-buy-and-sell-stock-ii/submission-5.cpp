class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
        {
            return 0;
        }
        int l = 0, r = 1, profit = 0, maxprof = 0;
        while(r <= (prices.size() - 1))
        {
            if(prices[l] <= prices[r])
            {
                if(profit > (prices[r] - prices[l]))
                {
                    maxprof += profit;
                    profit = 0;
                    l = r;
                }
                profit = prices[r] - prices[l];
            }
            if(prices[l] > prices[r])
            {
                maxprof += profit;
                profit = 0;
                l = r;
            }
            else
            {
                r++;
            }
            
        }
        maxprof += profit;
        return maxprof;
    }
};