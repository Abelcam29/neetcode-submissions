class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
        {
            return 0;
        }
        int l = 0, r = 1, profit = 0;
        while(r <= (prices.size() - 1))
        {
            if(prices[l] < prices[r])
            {
                int lm = prices[r] - prices[l];
                profit = max(lm, profit);
            }
            else
            {
                l = r;
            }
            r++;
        }
        return profit;
    }
};
