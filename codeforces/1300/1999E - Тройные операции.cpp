#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll maxN = 2e6;

int main(){
    int t;
    cin >> t;
    vector<ll> dp(maxN+1);
    vector<ll> pref(maxN+1);
        dp[0] = 0;
        for(int i=1;i<=maxN;i++){
            dp[i] = dp[i/3]+1;
            pref[i] = pref[i-1]+dp[i];
        }
    while(t--){
        ll l,r;
        cin >> l >> r;
        cout << pref[r] - pref[l-1] + dp[l] << endl;
    }
}