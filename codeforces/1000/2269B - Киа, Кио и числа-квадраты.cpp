#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Constants
const int INF = 1e9;
const int MOD = 1000000007;

//---  Fast I/O MACROS -----
#define fast_io \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

// Mathematics
ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    else {
        return gcd(b,a%b);
    }
}

ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}

ll mod_add(ll a,ll b,ll m = MOD){
    return (a%m+b%m)%m;
}

ll mod_sub(ll a,ll b, ll m = MOD){
    return (a%m - b% m+m)%m;
}

ll mod_multi(ll a,ll b,ll m = MOD){
    return (a%m*b%m)%m;
}

const int N = 1000000;

ll modpow(ll a,ll b){
    ll ans = 1;
    while(b>0){
        if(b & 1){
            ans = ans*a;
        }
        a = a*a;
        b >>= 1;
    }
    return ans;
}

ll fact[N+1];
ll invfact[N+1];

void precompute(){
    //Factorial
    fact[0] = 1;
    for(int i=1;i<=N;i++){
           fact[i] = fact[i-1]*i % MOD;
    }
    //inverse factorial
    invfact[N] = modpow(fact[N],MOD-2);
    for(int i=1;i<N;i++){
        invfact[i-1] = invfact[i]*i % MOD;
    }
}


// ----- SOLVE ------


ll square(ll a){
    ll res = 0;
    while(a!=0){
    ll remain = a%10;
    res += (remain*remain);
    a /= 10;
    }
    return res;
}

void solve(ll test){
   ll n;
   cin >> n;
   vector<ll> a(n);
   for(int i=0;i<n;i++){
    cin >> a[i];
   }
   ll count = 0;
   for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        ll a1 = square(a[i]);
        ll b1 = square(a[j]);
        for(int k=0;k<300;k++){
            if(a1==b1){
                count++;
                break;
            }
            a1 = square(a1);
            b1 = square(b1);
        }
    }
   }
   cout << count << endl;
}




// ---- MAIN -----
int main(){
    fast_io
    long long t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}