class Solution {
public:
     //if we reach same needs so thats why dp.
    map<vector<int>,int>dp;
    int helper(vector<int>& price,vector<vector<int>>& special,vector<int>& needs){
         //if i already have that needs there is no need to calculate it back we direcctly return with help of dp.
        if(dp.count(needs)){
            return dp[needs];
        }
        //dont use offers
        int ans = 0;
        for(int i=0;i<needs.size();i++){
            ans += price[i]*needs[i];
        }
        //use offers,reduce needs,use recursion for remaining needs
        for(auto it:special){
            bool ok = true;
            for(int i=0;i<needs.size();i++){
                if(it[i]>needs[i]){
                    ok = false;
                    break;
                }
            }
        if(ok){
            for(int i=0;i<needs.size();i++){
             needs[i] -= it[i];
            }
             //After applying offers we need to keep updating ans which is individual buying
             ans = min(ans,it.back()+helper(price,special,needs));
             //Backtrack
             for(int i=0;i<needs.size();i++){
                needs[i] += it[i];
             }
        }
        }
        return dp[needs] = ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return helper(price,special,needs);
    }
};