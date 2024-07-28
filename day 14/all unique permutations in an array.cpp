//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void helper(vector<int>&vec, vector<int>&vis, int n,set<vector<int>>&st, vector<int>&arr){
        if(vec.size()==n){
            st.insert(vec);
            return;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                vec.push_back(arr[i]);
                helper(vec,vis,n,st,arr);
                vis[i]=0;
                vec.pop_back();
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
       sort(arr.begin(),arr.end());
       vector<int>vec;
       vector<int>vis(n,0);
       set<vector<int>>st;
       helper(vec,vis,n,st,arr);
       vector<vector<int>>ans(st.begin(),st.end());
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
