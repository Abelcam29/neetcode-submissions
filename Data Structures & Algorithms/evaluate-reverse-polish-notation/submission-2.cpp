class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int total = 0;
        stack<int> mp;
        for(string& st : tokens)
        {
            if(st == "+")
            {
                int a = mp.top();
                mp.pop();
                int b = mp.top();
                mp.pop();
                total = a + b;
                mp.push(total);
            }
            else if(st == "/")
            {
                int a = mp.top();
                mp.pop();
                int b = mp.top();
                mp.pop();
                total = b / a;
                mp.push(total);
            }
            else if(st == "-")
            {
                int a = mp.top();
                mp.pop();
                int b = mp.top();
                mp.pop();
                total = b-a;
                mp.push(total);                       
            }
            else if(st == "*")
            {
                int a = mp.top();
                mp.pop();
                int b = mp.top();
                mp.pop();
                total = b*a;
                mp.push(total);                
            }
            else
            {
                int num = stoi(st);
                mp.push(num);
            }
        }
        total = mp.top();
        return total;
    }
};
