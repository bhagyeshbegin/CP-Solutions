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
   ll n;
   cin >> n;
   vector<ll> d(n+1);
   for(int i=1;i<=n;i++){
    cin >> d[i];
   }
   vector<ll> l(n+1),r(n+1);
   for(int i=1;i<=n;i++){
    cin >> l[i] >> r[i];
   }
   vector<ll> low(n+1),high(n+1);
   for(int i=1;i<=n;i++){
    //this is possible range for i
    if(d[i]==0){
       low[i] = low[i-1];
       high[i] = high[i-1];
    }
    else if(d[i]==1){
    low[i] = low[i-1]+1;
    high[i] = high[i-1]+1;
} 
    else {
        low[i] = low[i-1];
        high[i] = high[i-1]+1;
    }
    //but there are obstacles also so we intersect
    low[i] = max(low[i],l[i]);
    high[i]  = min(high[i],r[i]);  //this is the actual range for i
    if(low[i]>high[i]){
        cout << -1 << endl;
        return;
    }
   }
   //reconstruct
   //backwards
   int h = low[n];
   for(int i=n;i>=1;i--){
      //d[i]=h[i]-h[i-1]
    if(d[i]==0){
        h = h;
    }
    else if(d[i]==1){
        h-=1;
    }
    else {
        //1st we use d[i]=0
        //we need to check whether h[i-1] is in range of i-1 or not. so h[i-1]=h[i] so will check current h
        if(low[i-1]<=h && h<=high[i-1]){
            d[i] = 0;
        }
        else {
            d[i] = 1;
            h-=1;
        }
    }
   }
   for(int i=1;i<=n;i++){
    cout << d[i] << " ";
   }
   cout << endl;
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