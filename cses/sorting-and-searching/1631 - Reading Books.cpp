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
    sort(a.begin(),a.end());
    long long sum = 0;
    for(int i=0;i<n;i++){
        sum += a[i];
    }
    if(sum-a.back()<a.back()){
      cout << 2*a.back() << endl;
    }
    else {
        cout << sum << endl;
    }
}