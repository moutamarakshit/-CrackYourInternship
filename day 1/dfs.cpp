//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void helper(int node, int* vis, vector<int>adj[], vector<int>&list){
        vis[node]=1;
        list.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
            helper(it,vis,adj,list);
                
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       int vis[V]={0};
       vis[0]=1;
       vector<int>list;
       helper(0,vis,adj,list);
       return list;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
