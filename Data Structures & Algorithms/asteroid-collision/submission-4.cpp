class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> dp;
        for(int asteroid : asteroids)
        {
            if(asteroid > 0)
            {
                dp.push(asteroid);
            }
            else
            {
                bool destruido = false;

                while(!dp.empty() && dp.top() > 0)
                {
                    if(dp.top() == abs(asteroid))
                    {
                        dp.pop();
                        destruido = true;
                        break;
                    }
                    else if(dp.top() > abs(asteroid))
                    {
                        destruido = true;
                        break;
                    }
                    else
                    {
                        dp.pop();
                    }
                }
                if(!destruido)
                {
                    dp.push(asteroid);
                }
            }
        }
        vector<int> res(dp.size());
        for(int i = dp.size() - 1; i >= 0; i--)
        {
            res[i] = dp.top();
            dp.pop();
        }
        return res;
    }
};