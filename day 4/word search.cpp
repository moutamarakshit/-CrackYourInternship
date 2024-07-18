class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board,
             vector<vector<int>>& vis, string word, int n, int m, int g) {
        if (g == word.size())
            return true;
        vis[i][j] = 1;
        int drow[] = {0, 0, 1, -1};
        int dcol[] = {1, -1, 0, 0};
        for (int k = 0; k < 4; k++) {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                board[nrow][ncol] == word[g] && vis[nrow][ncol] != 1) {
                if (dfs(nrow, ncol, board, vis, word, n, m, g + 1) == true)
                    return true;
            }
        }
        vis[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int>> vis(n, vector<int>(m, 0));
                    if (dfs(i, j, board, vis, word, n, m, 1) == true)
                        return true;
                }
            }
        }
        return false;
    }
};
