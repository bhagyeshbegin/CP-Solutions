class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        long long n = nums.size();
        vector<unsigned int> dp(target+1,0);
        dp[0] = 1;
        for(long long i=1;i<=target;i++){
            for(long long  j=0;j<n;j++){
                long long currentnum = nums[j];
                if(i-currentnum>=0){
                    dp[i] += dp[i-currentnum];
                }
            }
        }
        return dp[target];
    }
};