class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       //dp[i] =  this will store minimum number of coin required to form i coint.
       vector<int> dp(amount+1,INT_MAX);
       //base case
       dp[0] = 0;
       //transition
       for(int i=1;i<=amount;i++){
           for(auto x:coins){
            if(i>=x && dp[i-x]!=INT_MAX){
            dp[i] = min(dp[i],dp[i-x]+1);
           }
           }
       }
       if(dp[amount]==INT_MAX){
        return -1;
       }
       //final subproblem
    return dp[amount];
    }
};