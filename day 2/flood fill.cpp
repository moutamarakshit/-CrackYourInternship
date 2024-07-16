class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>vis=image;
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=color;
        int col=image[sr][sc];
        if(col==color) return image;
        int drow[]={0,0,1,-1};
        int dcol[]={1,-1,0,0};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==col){
                    vis[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        return vis;
    }
};
