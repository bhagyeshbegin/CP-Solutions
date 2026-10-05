class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        int count = 0;
        int score = 0;
        int score1 = 1;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                count++;
            }
            else {
                count--;
                    if(s[i-1]=='('){
                        score += pow(2,count);
                    }
                }
            }
        return score;
    }
};