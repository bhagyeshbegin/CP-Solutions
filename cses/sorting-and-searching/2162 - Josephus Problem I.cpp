#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(vector<ll> a){
    ll n = a.size();
    if(n==1){
        cout << a[0] << " ";
        return;
    }
    vector<ll> a1;
    for(int i=0;i<n;i++){
        if(i%2==1){
            cout << a[i] << " ";
        }
        else {
          a1.push_back(a[i]);
        }
    }
    if(n%2==1){
       rotate(a1.begin(),a1.end()-1,a1.end());
    }
    solve(a1);
}

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        a[i] = i+1;
    }
    solve(a);
}