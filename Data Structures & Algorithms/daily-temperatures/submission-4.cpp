class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        for(int i = temperatures.size() - 1; i >= 0; i--)
        {
            st.push(temperatures[i]);
        }
        stack<int> temp;
        st.pop();
        temp = st;
        vector<int> res(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++)
        {
            int sum = 1;
            while(!temp.empty() && temperatures[i] >= temp.top())
            {
                sum++;
                temp.pop();
            }
            if(temp.empty())
            {
                sum = 0;
            }
            res[i] = sum;
            st.pop();
            temp = st;
            if(st.empty())
            {
                break;
            }
        }

        return res;
    }
};
