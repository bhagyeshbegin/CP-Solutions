class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(501);
        int ans = 0;
        long long bad = 0;
         auto add = [&](int x) {
        //a+b=x
        for(int a=1;a<=500;a++){
            int b = x-a;
            if(b<1 || b>500){
                continue;
            }
            //special case
            if(a==b){
                bad += 1LL*freq[a]*(freq[a]-1)/2;
            }
            else if(a<b){
                bad += 1ll*freq[a]*freq[b];
            }
        }
        //case 2-: a+x=b
        for(int a=1;a+x<=500;a++){
            int b = a+x;
            bad += 1ll*freq[a]*freq[b];
        }
        freq[x]++;
         };
             auto remove = [&](int x) {
                freq[x]--;
                //a+b=x
        for(int a=1;a<=500;a++){
            int b = x-a;
            if(b<1 || b>500){
                continue;
            }
            //special case
            if(a==b){
                bad -= 1LL*freq[a]*(freq[a]-1)/2;
            }
            else if(a<b){
                bad -= 1ll*freq[a]*freq[b];
            }
        }
        for(int a=1;a+x<=500;a++){
            int b = a+x;
            bad -= 1ll*freq[a]*freq[b];
        }
             };
             int left = 0;
       for(int right=0;right<n;right++){
          add(nums[right]);
          while(bad>0){ 
            remove(nums[left]);
            left++;
          }
          ans = max(ans,right-left+1);
       }
       return ans;
    }
};