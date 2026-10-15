class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        set<long long> st;
         for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               st.insert(nums[j]);
               sum += (st.size()*st.size());
            }
            st.clear();
         }
         return sum;
    }
};