class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> required(n,-1);
        int maximum = 1;
        int maxindex = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
               if(nums[i]%nums[j]==0){
                if(dp[j]+1>dp[i]){ //if maximum j satisfy the condition will take the largest one.
                dp[i] = dp[j]+1;
                required[i] = j;
                }
               }
            }
            if(maximum<dp[i]){
                maximum = dp[i];
                maxindex = i;
            }
        }
        vector<int> ans;
        int currlength = maxindex;
        while(currlength!=-1){
         ans.push_back(nums[currlength]);
         currlength = required[currlength];//before maxlength which elements are valid to fornm subset.
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};