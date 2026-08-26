#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool helper(ll mid,vector<ll> a,ll h){
    ll intial  = h;
    //1...mid
    // we need to sort and reverse first mid elements
    sort(a.begin(),a.begin()+mid);
    reverse(a.begin(),a.begin()+mid);
    for(int i=0;i<mid;i++){
      if(a[i]<=intial){
        intial -= a[i];
        if(i+1<mid){
            i++;
        }
      }
      else {
        return false;
      }
    }
    return true;
}

int main(){
    ll n,h;
    cin >> n >> h;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        }
        ll s = 1;
        ll e = n;
        ll ans = -1;
        //TTTTTFFFFF
        while(s<=e){
            ll mid = s+(e-s)/2;
            if(helper(mid,a,h)){
                ans = mid;
               s = mid+1;
            }
            else {
                e = mid-1;
            }
        }
        cout << ans << endl;
}