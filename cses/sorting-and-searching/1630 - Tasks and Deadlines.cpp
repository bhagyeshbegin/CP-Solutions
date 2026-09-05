#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<pair<ll,ll>> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(),a.end());
    ll t = 0;
    ll ans = 0;
    for(int i=0;i<n;i++){
        t += a[i].first;
        ans += (a[i].second-t);
    }
    cout << ans << endl;
}