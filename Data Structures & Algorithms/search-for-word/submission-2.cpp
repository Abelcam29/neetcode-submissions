class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int f, int c, int idx, vector<vector<bool>>& visited)
    {
        int n = board.size();
        int m = board[0].size();
        if(idx == word.size())
        {
            return true;
        }
        if(f > 0)
        {
            if(board[f-1][c] == word[idx] && !visited[f-1][c])
            {
                visited[f-1][c] = true;
                bool res = dfs(board, word, f-1, c, idx+1, visited);
                visited[f-1][c] = false;
                if(res)
                {
                    return true;
                }
            }
        }
        if(f < n - 1 && n > 1)
        {
            if(board[f+1][c] == word[idx] && !visited[f+1][c])
            {
                visited[f+1][c] = true;
                bool res = dfs(board, word, f+1, c, idx+1, visited);
                visited[f+1][c] = false;                
                if(res)
                {
                    return true;
                }
            }
        }
        if(c > 0)
        {
            if(board[f][c-1] == word[idx] && !visited[f][c-1])
            {
                visited[f][c-1] = true;
                bool res = dfs(board, word, f, c-1, idx+1, visited);
                visited[f][c-1] = false;                
                if(res)
                {
                    return true;
                }
            }
        }
        if(c < m - 1 && m > 1)
        {
            if(board[f][c+1] == word[idx] && !visited[f][c+1])
            {
                visited[f][c+1] = true;
                bool res = dfs(board, word, f, c+1, idx+1, visited);
                visited[f][c+1] = false;                
                if(res)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        bool res = false;
        vector<vector<bool>> visited(n, vector(m, false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == word[0])
                {
                    visited[i][j] = true;
                    res = dfs(board, word, i, j, 1, visited);
                    if(res)
                    {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};
