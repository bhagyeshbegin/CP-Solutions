#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> fact;
        for(int i=2;i*i<=n;i++){
            if(n%i!=0){
                continue;
            }
            n/=i;
            fact.push_back(i);
            if(fact.size()==2){
                break;
            }
        }
        ll last = n;  // so c will be last remaining n.
        if(fact.size()<2 || n==fact[0] || n==fact[1]){  //prime number
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            cout << fact[0] << " " <<fact[1] << " " << last << endl;
        }
    }
}