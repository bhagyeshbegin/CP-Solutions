class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int count = 0;
        int count1 = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                count++;
                count1 = max(count,count1);
            }
            else if(s[i]==')'){
                count--;
            }
        }
        return count1;
    }
};