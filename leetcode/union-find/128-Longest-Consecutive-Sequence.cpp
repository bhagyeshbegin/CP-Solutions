class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        map<int,int> mp;
        for(int i=0;i<n;i++){
           mp[nums[i]]++;
        }
        if(mp.empty()){
            return 0;
        }
        auto it = mp.begin();
        auto nextit = next(it);
        int maximum = 1;
        while(nextit!=mp.end()){
            if(nextit->first-it->first==1){
                count++;
                maximum = max(maximum,count);
            }
            else {
                count = 1;
            }
            it = nextit;
            nextit++;
        }
       return maximum;
    }
};