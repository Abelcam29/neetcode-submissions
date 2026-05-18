class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i = 0; i < operations.size(); i++)
        {
            if(operations[i] == "C")
            {
                st.pop();
            }
            else if(operations[i] == "D")
            {
                int temp;
                temp = st.top() * 2;
                st.push(temp);
            }
            else if(operations[i] == "+")
            {
                int temp;
                stack<int> tp(st);
                temp = tp.top();
                tp.pop();
                temp += tp.top();
                st.push(temp);
            }
            else
            {
                int num = stoi(operations[i]);
                st.push(num);
            }
        }
        int sum = 0;
        while(!st.empty())
        {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};