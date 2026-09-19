class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();
        stack<long long> st;
        unordered_map<long long,long long> mp;
        long long count = 0;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]<st.top()){
                mp[st.top()]--; //we are popping out elements which are greater than x and also removing its occurences. In stack we are storing all previous elements which are <x.
                st.pop();
            }
            count += (st.size()-mp[nums[i]]);  //we need to also remove the equal elements
            st.push(nums[i]);
            mp[nums[i]]++;
        }
        return count;
    }
};