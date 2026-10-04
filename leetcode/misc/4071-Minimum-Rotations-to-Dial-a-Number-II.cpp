class Solution {
public:
     int dist(char a,char b){
        int diff = abs((a-'0')-(b-'0'));
        return min(diff,10-diff);
     }
    int minRotations(int n, string s) {
        vector<int> pref(n);
        pref[0] = dist('0',s[0]);
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]+dist(s[i-1],s[i]);
        }
        vector<int> suff(n);
        for(int i=n-2;i>=0;i--){
            suff[i]  = suff[i+1]+dist(s[i],s[i+1]);
        }
        int minimum = INT_MAX;
        int curr;
        for(int k=0;k<n;k++){
            if(k==0){
              curr = dist('0',s[n-1])+suff[0];
            } 
            else {
                curr = pref[k-1]+dist(s[k-1],s[n-1])+suff[k];
            }
            minimum = min(minimum,curr);
        }
        return minimum;
    }
};