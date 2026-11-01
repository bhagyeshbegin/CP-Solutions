class Solution {
public:
    int merge(int num1,int num2){
        return stoi(to_string(num1)+to_string(num2));
    }
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int minimum = INT_MAX;
        for(int i=0;i<n;i+=2){
            minimum = min(minimum,merge(nums[i],nums[i+1]));
        }
        return minimum;
    }
};