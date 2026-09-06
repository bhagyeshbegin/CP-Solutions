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

long long binpow(long long a, long long b)
{
    long long res = 1;
 
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
 
        a = a * a;
        b >>= 1;
    }
 
    return res;
}


// ----- SOLVE ------

void solve(ll test){
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> a(n+1);
     for(int i=1;i<=n;i++){
        cin >> a[i];
     }
     vector<ll> l(m+1,0);
     vector<ll> r(m+1,0);
     vector<ll> d(m+1,0);
     for(int i=1;i<=m;i++){
        cin >> l[i] >> r[i] >> d[i];
     }
     vector<ll> count(m+2,0);
     for(int i=1;i<=k;i++){
        ll x,y;
        cin >> x >> y;
        count[x]++;
        count[y+1]--;
     }
    for(int i=1;i<=m;i++){
        count[i] += count[i-1];
    }
    vector<ll> diff(n+2,0);
    for(int i=1;i<=m;i++){
        diff[l[i]] += d[i]*count[i];
        diff[r[i]+1] -= d[i]*count[i];
    }
    for(int i=1;i<=n;i++){
        diff[i] += diff[i-1];
    }
    for(int i=1;i<=n;i++){
        a[i] += diff[i];
    }
    for(int i=1;i<=n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
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