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
   ll n,m,q;
   cin >> n >> m >> q;
   ll g1 = __gcd(n,m);
while(q--){
    ll sx,sy,ex,ey;
    cin >> sx >> sy >> ex >> ey;
    //sx or ex can be 1 or 2 showing inner and outer.
    //n/g1 = inner sectors
    //m/g1 = outer sectors    
    ll size1 = (sx==1 ? n/g1:m/g1); 
    ll size2 = (ex==1 ?n/g1:m/g1);
     
    ll group1 = (sy-1)/size1;
    ll group2  = (ey-1)/size2;
    if(group1==group2){
      cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
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