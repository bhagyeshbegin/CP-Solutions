#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll MOD = 998244353;
ll modpow(ll a,ll b){
    ll ans = 1;
    while(b>0){
        if(b & 1){
            ans = ans*a % MOD;
        }
        a = a*a %  MOD;
        b >>= 1;
    }
    return ans;
}

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        vector<ll> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        ll ans = 1;
        for(int i=1;i<=k;i++){
            ans = ans*i % MOD;
        }
        ll ans1 = modpow(k,n-k);
        ll way = ans*ans1 % MOD;
        cout << way << endl;
    }
}
