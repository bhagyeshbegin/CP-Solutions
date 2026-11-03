#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    map<ll,ll> mp;
    set<pair<ll,ll>> st;
    auto update = [&](ll x,ll val){
      if(mp[x]>0){
        st.erase({mp[x],-x});
      }
      mp[x] += val;
      if(mp[x]>0){
        st.insert({mp[x],-x});
      }
      else {
        mp.erase(x);
      }
    };
    ll left = 0;
    for(ll right=0;right<n;right++){
        update(a[right],1);
        if(right-left+1>k){
            update(a[left],-1);
            left++;
        }
        if(right-left+1==k){
            cout << -st.rbegin()->second << " ";
        }
    }
}