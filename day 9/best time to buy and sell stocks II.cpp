class Solution {
public:
    int helper(vector<vector<int>>&dp,int ind, int buy, int n,vector<int>&prices ){
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        long long profit=0;
        if(buy){
            profit=max(-prices[ind]+helper(dp,ind+1,0,n,prices),helper(dp,ind+1,1,n,prices));
        }
        else{
            profit=max(prices[ind]+helper(dp,ind+1,1,n,prices),helper(dp,ind+1,0,n,prices)); 
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(dp,0,1,n,prices);
    }
};
