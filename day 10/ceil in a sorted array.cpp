//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        sort(arr.begin(),arr.end());
       int n=arr.size();
       int low=0,high=n-1,floor=-1,ceil=-1;
       while(low<=high){
           int mid=low+(high-low)/2;
           if(arr[mid]<=x){
               floor=mid;
               low=mid+1;
           }
           if(arr[mid]>=x){
               ceil=mid;
               high=mid-1;
           }
       }
       vector<int>vec;
       if(floor ==-1)
       vec.push_back(floor);
       else vec.push_back(arr[floor]);
       if(ceil==-1)
       vec.push_back(ceil);
       else vec.push_back(arr[ceil]);
       return vec;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
