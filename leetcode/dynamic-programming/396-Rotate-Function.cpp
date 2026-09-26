class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long n = nums.size();
        long long sum = 0;
        long long f0 = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            f0 += (1ll*i*nums[i]);
        }
        vector<long long> dp(n,0);
        dp[0] = f0;//f0 is also valid rotation.
        long long maximum = f0;
        for(long long i=1;i<n;i++){
            dp[i] = dp[i-1]+sum-(1ll*n*(nums[n-i]));
            maximum = max(maximum,dp[i]);
        }
        return maximum;
    }
};