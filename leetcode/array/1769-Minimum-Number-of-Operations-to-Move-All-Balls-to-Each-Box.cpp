class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> ans(n,0);
        int moves = 0;
        int m1 = 0;
        for(int i=0;i<n;i++){
            ans[i] += moves;
            m1 += (boxes[i]-'0');
            moves += m1;
        }
        int moves1 = 0;
        int m2 = 0; 
        for(int i=n-1;i>=0;i--){
            ans[i] += moves1;
            m2 += (boxes[i]-'0');
            moves1 += m2;
        }
        return ans;
    }
};