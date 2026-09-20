class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(auto s1:strs){
            int c0 = count(s1.begin(),s1.end(),'0');
            int c1 = count(s1.begin(),s1.end(),'1');
            for(int i=m;i>=c0;i--){
                for(int j=n;j>=c1;j--){
                    //take not string
                    //take string
                    dp[i][j] = max(dp[i][j],1+dp[i-c0][j-c1]);
                }
            }
        }
        return dp[m][n];
    }
};