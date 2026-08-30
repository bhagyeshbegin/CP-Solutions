#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n,target;
    cin >> n >> target;
    vector<ll> a(n);
    map<ll,ll> mp;
    mp[0] = 1;
    for(int i=0;i<n;i++){
         cin >> a[i];
    }
    ll sum = 0;
    ll count = 0;
    for(int i=0;i<n;i++){
        sum += a[i];
        count += mp[sum-target];
        mp[sum]++;   //pref[l-1]==pref[r]-target;
    }
    cout << count << endl;
}