//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int i, int j, vector<vector<char>>&mat,vector<vector<int>>&vis, int n, int m){
        vis[i][j]=1;
        int drow[]={0,0,1,-1};
        int dcol[]={1,-1,0,0};
        for(int k=0;k<4;k++){
            int nrow=i+drow[k];
            int ncol=j+dcol[k];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]==0 && mat[nrow][ncol]=='O')
            dfs(nrow,ncol,mat,vis,n,m);
        }
        
        
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<char>>ans=mat;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0||i==n-1||j==m-1) && mat[i][j]=='O' && vis[i][j]==0)
                dfs(i,j,mat,vis,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' && vis[i][j]==0)
                ans[i][j]='X';
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
