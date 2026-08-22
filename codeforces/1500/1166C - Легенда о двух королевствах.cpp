#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    ll count = 0;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
      int j = upper_bound(a.begin(),a.end(),2*a[i])-a.begin();
    count += (j-i-1);
    }
    cout << count << endl;
}