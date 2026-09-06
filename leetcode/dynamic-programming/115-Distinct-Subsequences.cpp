class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,0));
        //state-: dp[i][j] no of ways to form t[0,1,2,.....,j-1] using s[0,1,2,...i-1]
        //Base case-: To form t when it is empty there is only one wAY choose nothing
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        //Transition-:
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
              // when s[i] == t[j]
              //Choose s[i] or dont choose
              if(s[i-1]==t[j-1]){
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
              }
              else {
                //not equal
                //move to other s[i]
                dp[i][j] = dp[i-1][j];
              }
            }
        }
        return dp[n][m];
    }
};