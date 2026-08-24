#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, x,m;
        cin >> n >> x >> m;
        ll minimum = x;
        ll maximum = x;
        for(int i=0;i<m;i++){
            ll l,r;
            cin >> l >> r;
            if(minimum<=r && maximum>=l){ //merge
                minimum = min(minimum,l);  
                maximum = max(maximum,r);
            }
        }
        cout << maximum-minimum+1 << endl;
    }
}