class Solution {
public:
    vector<string> ans1;
    void helper(int n,int open,int close,string ans){
        if(open==n && close==n){
            ans1.push_back(ans);
            return;
        }
        if(open+close>2*n){
            return;
        }
        if(open<n){
            ans.push_back('(');
            helper(n,open+1,close,ans);
            ans.pop_back();
        }
        if(close<open){
            ans.push_back(')');
            helper(n,open,close+1,ans);
            ans.pop_back();
    }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n,0,0,"");
        return ans1;
    }
};