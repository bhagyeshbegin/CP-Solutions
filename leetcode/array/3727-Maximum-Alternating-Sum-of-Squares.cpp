class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> a1;
        for(int i=0;i<n;i++){
            a1.push_back(1ll*nums[i]*nums[i]);
        }
        sort(a1.begin(),a1.end());
        long long sum = 0;
        for(int i=0;i<n/2;i++){
              sum -= a1[i];
        }
        for(int i=n/2;i<n;i++){
          sum += a1[i];
        }
        return sum;
    }
};