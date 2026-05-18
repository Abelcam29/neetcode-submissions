class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> rt;
        for(string& st : operations)
        {
            if(st == "+")
            {
                int a = rt.top(), b = 0;
                rt.pop();
                b = rt.top();
                rt.push(a);
                rt.push(a + b);
            }
            else if(st == "D")
            {
                int temp = rt.top();
                rt.push(temp * 2);
            }
            else if(st == "C")
            {
                rt.pop();
            }
            else
            {
                int num = stoi(st);
                rt.push(num);
            }
        }
        int sum = 0;
        while(!rt.empty())
        {
            sum += rt.top();
            rt.pop();
        }
        return sum;
    }
};