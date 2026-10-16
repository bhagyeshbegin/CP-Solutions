class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        vector<int> ans(n,-1);
        long long sum = 0;
        for(int right=0;right<n;right++){
            sum += nums[right];
            while(right-left+1>(2*k+1)){
                sum -= nums[left];
                left++;
            }
            if(right-left+1==(2*k+1)){
              ans[left+k] = sum/(2*k+1);
            }
        }
       return ans;
    }
};