#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9+7;

int main(){
    ll n;
    cin >> n;
     vector<ll> a(n);
     for(int i=0;i<n;i++){
        cin >> a[i];
     }
     map<ll,ll> mp;
     for(int i=0;i<n;i++){
        mp[a[i]]++;
     }
     ll ans = 1;
     for(auto it:mp){
        ans *= (it.second+1);
        ans %=mod;
     }
     cout << ans-1 << endl;
}