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
ll n,k;
vector<ll> q,r;

bool check(ll mid){
    for(int i=0;i<mid;i++){
        //we need to first i q as minimum and i r as maximum as wee nedd to balance x.
        // Both q and r if large will increase x so to balance this we did this.
        ll x = (q[i]+1)*(r[mid-i-1]+1)-1;  //derived the formula and simplifed it.
        if(x>k){
            return false;
        }
    }
    return true;
}

void solve(ll test){
   cin >> n >> k;
    q.resize(n);
    r.resize(n);
    for(int i=0;i<n;i++){
        cin >> q[i];
    }
    for(int i=0;i<n;i++){
        cin >> r[i];
    }
    sort(q.begin(),q.end());
    sort(r.begin(),r.end());
    //n is total operations.
    ll l  = 0;
    ll e = n+1;
    while(e-l>1){
        ll mid = l+(e-l)/2;
        if(check(mid)){
            l = mid;
        }
        else {
            e = mid;
        }
    }
    cout << l << endl;
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