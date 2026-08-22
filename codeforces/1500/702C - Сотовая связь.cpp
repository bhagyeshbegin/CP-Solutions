#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(ll mid,vector<ll>& a,vector<ll>& b){
     ll i = 0;
     ll j = 0;
     ll n = a.size();
     ll m = b.size();
     while(i<n && j<m){
         if(abs(a[i]-b[j])<=mid){
             i++;
         }
         else {
            j++;
         }
     }
    return i==n;
}

int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<ll> b(m);
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    ll ans = -1;
    ll s = 0;
    ll e = 2e9;
    while(s<=e){
       ll mid = s+(e-s)/2;
       if(check(mid,a,b)){
        ans = mid;
        e = mid-1;
       }
       else {
         s = mid+1;
       }
    }
    cout << ans << endl;
}