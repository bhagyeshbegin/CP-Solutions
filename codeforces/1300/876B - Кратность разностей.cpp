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
            ans = ans*a % MOD;
        }
        a = a*a %  MOD;
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

void solve(ll test){
   ll n,k,m;
   cin >> n >> k >> m;
   vector<ll> a(n);
   for(int i=0;i<n;i++){
    cin >> a[i];
   }
   vector<vector<ll>> a1(m);
   for(int i=0;i<n;i++){
      a1[a[i]%m].push_back(a[i]);
   }
   for(int i=0;i<m;i++){
    if(a1[i].size()>=k){
        cout << "Yes" << endl;
        for(int j=0;j<k;j++){
            cout << a1[i][j] << " ";
        }
        cout << endl;
        return;
    }
   }
   cout << "No" << endl;
}



// ---- MAIN -----
int main(){
    fast_io
    long long t = 1;
    
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}