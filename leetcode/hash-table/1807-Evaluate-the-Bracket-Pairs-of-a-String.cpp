class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        unordered_map<string,string> mp;
         for(auto k:knowledge){
            mp[k[0]] = k[1]; //mapping key with value.
         }
         string res;
         for(int i=0;i<n;i++){
            if(s[i]=='('){
                int j = s.find(')',i+1);//start searching after i.
                string sub = s.substr(i+1,j-i-1);
                if(mp.find(sub)!=mp.end()){   /*need to check whether substring is same as key.*/
                    res += mp[sub];
                }
                else {
                    res += '?';
                }
                i = j; //after finding skip ')'
            }
            else {
                res += s[i];
            }
         }
         return res;
    }
};