#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(2*n+1);
        for(int i=1;i<=2*n;i++){
            cin >> a[i];
        }
        //will store the indexes of a[i]
        vector<ll> occ(n+1,-1);
        for(int i=1;i<=2*n;i++){
            if(occ[a[i]]==-1){
                occ[a[i]] = i;  //just want to store first occurence of a[i]
            }
        }
        vector<ll> dp(2*n+1,0);
        dp[0] = 0;
        for(ll i=1;i<=2*n;i++){
            ll L = occ[a[i]]; //tAKING L as first occurence of a[i].
            //from 1 to i-1 will get deleted and last i will be handled sepeartly
            dp[i] = dp[i-1]+1;
            //Transition
            dp[i] = max(dp[i],((i-L+1)*(i-L+1))+dp[L-1]);
        }
        cout << dp[2*n] << endl;
    }
}