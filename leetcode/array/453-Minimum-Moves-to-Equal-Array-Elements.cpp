class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int minimum = nums[0];
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(minimum>nums[i]){
                minimum = nums[i];
            }
        }
        return sum-(n*minimum);
    }
};