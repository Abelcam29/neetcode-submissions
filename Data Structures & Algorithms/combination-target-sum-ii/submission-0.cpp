class Solution {
    vector<vector<int>> res;
public:
    void dfs(vector<int>& candidates, vector<int>& path, int target, int start)
    {
        if(target == 0)
        {
            res.push_back(path);
        }
        else
        {
            for(int i = start; i < candidates.size(); i++)
            {
                int sum = target - candidates[i];
                if(i > start && candidates[i] == candidates[i - 1])
                {
                    continue;
                }
                if(sum >= 0)
                {
                    path.push_back(candidates[i]);
                    dfs(candidates, path, sum, i+1);
                    path.pop_back();
                }
                else
                {
                    sum += candidates[i];
                }
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, path, target, 0);
        return res;        
    }
};
