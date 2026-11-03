class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        int highest = nums[n-1];
        for(int i=0;i<n;i++){
            ans += (abs(highest-nums[i]));
        }
        return ans;
    }
};