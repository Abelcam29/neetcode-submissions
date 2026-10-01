class StockSpanner {
private:
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int stan = 1;
        while(!st.empty() && st.top().first <= price)
        {
            stan += st.top().second;
            st.pop();
        }
        st.emplace(price, stan);
        return stan;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */