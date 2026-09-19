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
    ll n,q;
    cin >> n >> q;
    vector<vector<ll>> a1(n+1,vector<ll> (26,0));
    vector<vector<ll>> a2(n+1,vector<ll> (26,0));
    for(int i=1;i<=n;i++){
        char c;
        cin >> c;
        a1[i][c-'a']++;  //will store position and pointer of particular charcter

        for(int j=0;j<26;j++){
            a1[i][j] += a1[i-1][j]; //thought like prefix sum.
        }

    }
    for(int i=1;i<=n;i++){
        char c1;
        cin >> c1;
        a2[i][c1-'a']++;
        for(int j=0;j<26;j++){
            a2[i][j] += a2[i-1][j];
        }
    }
    while(q--){
        ll l,r;
        cin >> l >> r;

        ll ans = 0;
        ll freq1,freq2;
        for(int j=0;j<26;j++){
           freq1 = a1[r][j]-a1[l-1][j];
           freq2 = a2[r][j]-a2[l-1][j];
           if(freq1>freq2){
            ans += (freq1-freq2);
           }
        }
        cout << ans << endl;
    }
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