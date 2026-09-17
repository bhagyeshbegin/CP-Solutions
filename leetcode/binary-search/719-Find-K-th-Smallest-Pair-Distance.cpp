class Solution {
public:
    int countpairs(vector<int>& nums,int mid1){
         int n = nums.size();
         int left = 0;
         int count = 0;
         for(int right=0;right<n;right++){
            while(abs(nums[right]-nums[left])>mid1){
              left++;
            }
            count += (right-left);
         }
         return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n  = nums.size();
        sort(nums.begin(),nums.end());
        int low = 0;
        int high = nums[n-1]-nums[0]; //maximum diff
        while(low<high){
            int mid = low+(high-low)/2;
            //FFFFTTTTT
            if(countpairs(nums,mid)>=k){ //will find better
                high = mid;
            }
            else {
                low = mid+1;  //will find larger diff
            }
        }
        return low;
    }
};