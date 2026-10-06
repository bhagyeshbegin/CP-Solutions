class Solution {
public:
    bool vowel1(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pref(n,0);
        for(int i=0;i<n;i++){
            string temp = words[i];
            if(vowel1(temp[0]) && vowel1(temp[temp.length()-1])){
                pref[i]++; 
            }
        }
        for(int i=1;i<n;i++){
            pref[i] += pref[i-1];
        }
        vector<int> ans;
        for(auto it:queries){
             int l = it[0];
             int r = it[1];
             if(l==0){
                ans.push_back(pref[r]);
             }
             else {
                ans.push_back(pref[r]-pref[l-1]);
             }
        }
        return ans;
    }
};