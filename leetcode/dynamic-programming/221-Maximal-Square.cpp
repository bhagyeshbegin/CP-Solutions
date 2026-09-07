class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        //state-: dp[i][j] maximum area of square of 1s till right bottom corner i ,j
        vector<vector<int>> dp(n,vector<int>(m));
        //base case
        int area = 0;
        if(matrix[0][0]=='1'){
            dp[0][0] = 1;
        }
        else {
            dp[0][0] = 0;
        }
        //need to handle first row and column
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][0]=='1'){
                    dp[i][0] = 1;
                    area = 1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[0][j]=='1'){
                    dp[0][j] = 1;
                    area = 1;
                }
            }
    }
        //Transtion-: will choose minimum from top, left, diagonal
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='1'){
                // we need to balance the length so thats why minimum
                dp[i][j] = 1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
            }
            else {
                dp[i][j] = 0;
            }
            area  = max(area,dp[i][j]*dp[i][j]);
            }
        }
        //Final suproblem
        return area;
    }
};