#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
   int t;
   cin >> t;
   while(t--){
    ll n,m;
    cin >> n >> m;
    vector<ll> k(n);
    for(int i=0;i<n;i++){
        cin >> k[i];
    }
      vector<ll> c(m);
    for(int i=0;i<m;i++){
        cin >> c[i];
    }
    sort(k.rbegin(),k.rend());
    ll ans = 0;
    int j = 0;
    for(int i=0;i<n;i++){
         if(j<k[i] && c[j]<=c[k[i]-1]){
            ans += c[j];
            j++;
         }
         else {
            ans += c[k[i]-1];
         }
    }
    cout << ans << endl;
   }
}