class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        stack<int> st;
        int count = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push('(');
            }
            else {
                if(st.empty()){
                    if(i+1<n && s[i+1] ==')'){
                        count++;
                        i++;
                    }
                    else {
                        count += 2;
                    }
                }
                else {
                    if(i+1<n && s[i+1]==')'){
                        st.pop();
                        i++;
                    }
                    else {
                        count++;
                         st.pop();
                    }
                }
            }
        }
        return count+st.size()*2;
    }
};