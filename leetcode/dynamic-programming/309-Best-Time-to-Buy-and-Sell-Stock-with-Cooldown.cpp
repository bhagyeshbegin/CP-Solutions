class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(3,0));
        //holding the stock
        dp[0][0] = -prices[0];
        //buying the stock
        dp[0][1] = 0;
        //cooldown
        dp[0][2] = 0;
        for(int i=1;i<n;i++){
            //holding
            //two case-: 
            //1) will only happen if we are holding stock on previous day
            //2) will only happen if we need to buy the stock on previous day
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]-prices[i]);
            //buying
            //1) if would have bought stock on previous day
            //2) after cooldown
            dp[i][1] = max(dp[i-1][1],dp[i-1][2]);
            //cooldown
            //will only happen if we have sold the stock
        dp[i][2] = dp[i][0]+prices[i];
        }
        return max(dp[n-1][1],dp[n-1][2]);
    }
};