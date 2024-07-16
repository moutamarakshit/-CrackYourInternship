class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>&vis,vector<vector<char>>& grid,int m, int n){
        vis[i][j]=1;
        int drow[]={0,0,1,-1};
        int dcol[]={1,-1,0,0};
        for(int k=0;k<4;k++){
            int nrow=i+drow[k];
            int ncol=j+dcol[k];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1')
            dfs(nrow,ncol,vis,grid,m,n);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    count++;
                    dfs(i,j,vis,grid,m,n);
                }
            }
        }
        return count;
    }
};
