class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        unordered_map<char,int> mp1;
        unordered_map<char,int>mp2;
        for(int i=0;i<n1;i++){
          mp1[s1[i]]++;
        }
        int left = 0;
        for(int right=0;right<n2;right++){
            mp2[s2[right]]++;
            if(right-left+1>s1.length()){
               mp2[s2[left]]--;
               if(mp2[s2[left]]==0){ 
                mp2.erase(s2[left]);
               }
               left++;
            }
            if(right-left+1==s1.length()){
                if(mp1==mp2){
                    return true;
                }
            }
        }
        return false;
    }
};