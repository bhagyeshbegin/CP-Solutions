#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Constants
const ll INF = 4e18;
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
   ll n;
   cin >> n;
   vector<ll> a(n+1);
   for(int i=1;i<=n;i++){
    cin >> a[i];
   }
   vector<vector<ll>> dp(n+1,vector<ll> (2));
   //so will store minimum and maximum value of c
   dp[0][0] = 0;
   dp[0][1] = 0;
   for(int i=1;i<=n;i++){
    dp[i][0] = INF;
        dp[i][1] = -INF;
       ll x = dp[i-1][0]+a[i];
        ll y = dp[i-1][1]+a[i];
        dp[i][0] = min(dp[i][0],x);
        dp[i][0] = min(dp[i][0],abs(x));
        dp[i][1] = max(dp[i][1],x);
        dp[i][1] = max(dp[i][1],abs(x));

        dp[i][0] = min(dp[i][0],y);
        dp[i][0] = min(dp[i][0],abs(y));
        dp[i][1] = max(dp[i][1],y);
        dp[i][1] = max(dp[i][1],abs(y));
   }
   cout << dp[n][1] << endl;
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