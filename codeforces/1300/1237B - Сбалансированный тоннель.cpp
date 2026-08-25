#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
   ll n;
   cin >> n;
   vector<ll> a(n);
   for(int i=0;i<n;i++){
    cin >> a[i];
   }
   vector<ll> b(n);
   for(int i=0;i<n;i++){
    cin >> b[i];
   }
   map<ll,ll> mp;
   for(int i=0;i<n;i++){
    mp[a[i]] = i;
   }
    vector<ll> c(n);
    for(int i=0;i<n;i++){
        c[mp[b[i]]] = i; // will find b[i] in a[i] mapping.
    }
    ll count = 0;
    ll maximum = c[0];
    for(int i=0;i<n;i++){
        if(c[i]<maximum){  //jo max se kam hoge woh answer hoge
            count++;
        }
        maximum = max(maximum,c[i]); //upddate max
    }
    cout << count << endl;
}