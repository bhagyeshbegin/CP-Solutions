class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum&1){
            return false;
        }
        int target = sum/2;
        vector<bool> dp(target+1,false);
        dp[0] = true;
        for(auto x:nums){
            for(int j=target;j>=1;j--){
                if(j>=x){
                dp[j] = (dp[j-x] || dp[j]);
                }
                if(dp[target]==true){
                    return true;
                } 
            }
        }
        return dp[target];
    }
};