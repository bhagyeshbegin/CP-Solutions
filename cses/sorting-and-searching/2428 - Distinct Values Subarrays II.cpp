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
    ll left = 0;
    ll count = 0;
    map<ll,ll> mp;
    for(ll right=0;right<n;right++){
       mp[a[right]]++;
       while(mp.size()>k){
        mp[a[left]]--;
        if(mp[a[left]]==0){
            mp.erase(a[left]);
        }
        left++;
       }
       count += 1ll*(right-left+1);
    }
    cout << count << endl;
}