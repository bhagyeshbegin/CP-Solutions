class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int s = 1;
        int e = n;
        while(s<e){
            int mid = s+(e-s)/2;
            int count = 0;
            for(int i=0;i<n+1;i++){
                if(nums[i]<=mid){
                    count++;
                }
            }
            //By pigeonhole principle
            if(count>mid){
                //duplicate will lie in [1,mid]
                e = mid;
            }
            else {
                //dupliacte will lie in [mid+1,n]
                s = mid+1;
            }
        }
        return s;
    }
};