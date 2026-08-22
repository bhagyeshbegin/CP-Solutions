#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        bool ok = false;
        for(ll i=2;i*i<=n;i++){
            if(n%i==0){
                ll k1 = n/i;
                cout << k1 << " " << n-k1 << endl;
                ok = true;
                break;
            }
        }
        if(!ok){
            cout << 1 << " " << n-1 << endl;
        }
    }
}