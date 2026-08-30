class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n);
        dp[0] = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(dp[j]==true && j+nums[j]>=i){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};