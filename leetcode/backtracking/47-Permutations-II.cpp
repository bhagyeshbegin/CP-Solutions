class Solution {
public:
    vector<int> curr;
    vector<bool> done;
    vector<vector<int>> ans;
    void helper(vector<int>& nums){
        int n = nums.size();
       if(curr.size()==nums.size()){
          ans.push_back(curr);
       }
       for(int i=0;i<n;i++){
        if(done[i]==true){
            continue;
        }
        if(i>0 && nums[i]==nums[i-1] && done[i-1]==true){
            continue;
        }
        done[i] = true;
        curr.push_back(nums[i]);
        helper(nums);
        curr.pop_back();
        done[i] = false; 
       }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       done.assign(nums.size(), false);
        helper(nums);
        return ans;
    }
};