#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n+1);
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        ll totalsum = 0;
        vector<ll> pref(n+1,0);
        for(int i=1;i<=n;i++){
            totalsum += a[i];
            pref[i] = pref[i-1]+a[i];
        }
        ll dp = 0;
        ll bestleft = LLONG_MIN;
        for(int i=1;i<=n;i++){
           /*f[r] = r*r + r-pref[r]*/
            ll f = 1ll*i*i + i - pref[i];
           //g[r] = -(l*l)+l+pref[l-1]
           ll g = (-1ll*i*i) + i + pref[i-1];
           bestleft = max(bestleft,g);
           ll gain = f+bestleft;
           dp = max(dp,gain);
        }
        cout << totalsum + dp << endl;
    }
}