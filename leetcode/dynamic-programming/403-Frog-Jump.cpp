class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n =  stones.size();
         vector<vector<bool>> dp(n,vector<bool>(n+1,false));
         dp[0][0] = true;
         for(int i=0;i<n;i++){
            for(int lastjump=0;lastjump<=n;lastjump++){
                if(!dp[i][lastjump]){
                    continue;
                }
                for(int jump=lastjump-1;jump<=lastjump+1;jump++){
                    if(jump<=0){
                        continue;
                    }
                    int nextjump = stones[i]+jump;
                    for(int j=i+1;j<n;j++){
                        if(stones[j]==nextjump){
                            dp[j][jump] = true;
                            break;
                        }
                        if(stones[j]>nextjump){
                            break;
                        }
                    }
                }
            }
         }
         for(int i=0;i<=n;i++){
            if(dp[n-1][i]==true){
                 return true;
            }
         }
         return false;
    }
};