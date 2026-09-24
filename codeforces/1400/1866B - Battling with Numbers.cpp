#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 1e9;
const int MOD = 998244353;

#define fast_io \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

void solve(ll test){
    ll n;
    cin >> n;

    vector<ll> a(n),b(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<n;i++){
        cin >> b[i];
    }

    ll m;
    cin >> m;

    vector<ll> c(m),d(m);

    for(int i=0;i<m;i++){
        cin >> c[i];
    }

    for(int i=0;i<m;i++){
        cin >> d[i];
    }

    ll m1 = *max_element(a.begin(),a.end());
    ll m2 = *max_element(c.begin(),c.end());

    ll mx = max(m1,m2);

    vector<ll> a1(mx+1,0);
    vector<ll> b1(mx+1,0);

    for(int i=0;i<n;i++){
        a1[a[i]] = b[i];
    }

    for(int i=0;i<m;i++){
        b1[c[i]] = d[i];
    }

    ll ans = 1;

    for(int i=0;i<=mx;i++){
        if(a1[i]>b1[i]){
            ans = (ans*2)%MOD;
        }
        else if(a1[i]<b1[i]){
            cout << 0 << '\n';
            return;
        }
    }

    cout << ans << '\n';
}

int main(){
    fast_io;

    solve(1);

    return 0;
}