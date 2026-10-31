class Solution {
public:
    int m,n;
    int mod = 1e9+7;
        vector<vector<vector<int>>> dp;
        int helper(vector<vector<int>>& grid,int i,int j,int pos){
            if(i>=m || j>=n){
                return 0;
            }
            if(i==m-1 && j==n-1){
                return 1;
            }
            if(dp[i][j][pos]!=-1){
                return dp[i][j][pos];
            }
            if(grid[i][j]==1){
                if(pos==0){
                    return dp[i][j][pos] = helper(grid,i+1,j,1);
                }
                else {
                    return dp[i][j][pos] = helper(grid,i,j+1,0);
                }
            }
            return  dp[i][j][pos] = (helper(grid,i+1,j,1)+helper(grid,i,j+1,0))%mod; 
}
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if(grid[0][0]==1){
            return 0;
        }
         dp.assign(m, vector<vector<int>>(n, vector<int>(2, -1)));
        return helper(grid,0,0,0);
    }
};