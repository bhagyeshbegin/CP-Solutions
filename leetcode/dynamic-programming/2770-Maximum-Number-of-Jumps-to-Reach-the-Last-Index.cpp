class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
               if(nums[j]-nums[i]>=(-1*target) && nums[j]-nums[i]<=target && dp[j]>-1){
                 dp[i] = max(dp[i],dp[j]+1);
               }
            }
        }
        return dp[n-1];
    }
};