#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin>>s;
        long long ans = 1e10;
        for(int i = 0; i<s.size(); i++){
            string cur = "";
            for(int j = 0; j<s.size(); j++){
                if(j!=i){
                    cur += s[j];
                }
            } 
            long long x = stoi(cur);
            if(x < ans){
                ans = x;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
