class Solution {
public:
    bool check(int mid1,vector<int>& nums,int k,int n){
        int sum1 = 0;
        int count = 1;
        for(int i=0;i<n;i++){
            if(sum1+nums[i]>mid1){
                //will start new subarray
                count++;
                sum1 = nums[i];
            }
            else {
                sum1 += nums[i];
            }
        }
        //Agar k se kam ya equal suabbray ban rahe hai ham use aur choe part mai tod sakte hai.Agar <=mid jo sum hai agar woh pure 1 array mai ban raha hai toh woh uske andar ke parts mai bhi banega Type 1 greedy.
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        int ans = -1;
        int s = *max_element(nums.begin(),nums.end());
        int e = sum;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(check(mid,nums,k,n)){
                ans = mid;
                e = mid-1;
            }
            else {
                s = mid+1;
            }
        }
        return ans;
    }
};