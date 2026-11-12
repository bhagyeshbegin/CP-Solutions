class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int count = 1;
        int count1 = 1;
        for(int right=1;right<n;right++){
           if(nums[right]>nums[right-1]){
             count++;
             //reset decreasing 
             count1 = 1;
           }
           else if(nums[right]<nums[right-1]){
              count1++;
              //reset increasing 
              count = 1;
           }
           else {
              count = 1;
              count1 = 1;
           }
           ans = max(ans,max(count,count1));
        }
        return ans;
    }
};