class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //state-:dp[i] will store the minimum amount required to reach ith step.
        vector<int> dp(n);
        //base case.
        dp[0] = cost[0];
        dp[1] = cost[1];
        //transition.
        for(int i=2;i<n;i++){
          dp[i] = cost[i]+ min(dp[i-1],dp[i-2]);
        }
        //final subproblem.
        return min(dp[n-1],dp[n-2]);
    }
};