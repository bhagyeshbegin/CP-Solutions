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
ll a[200005],b[200005],c[200005];

bool check(ll mid1){
    ll cost = 0;
    for(int i=0;i<n;i++){
        ll sum = a[i]+b[i]+c[i];
        if(sum>=mid1){
            continue;
        }
       if(a[i]==b[i] && b[i]==c[i]){
        return false;
       }
       if(a[i]>b[i] || a[i]>c[i] || b[i]>c[i] ){
        cost += mid1-sum;
       }
       else {
        ll penalty = min(b[i]-a[i]+1,c[i]-b[i]+1);
        cost += mid1-sum+2*penalty;
       }
    if(cost>k){
        return false;
    }
}
return true;
}

void solve(ll test){
    cin >> n >> k;
   long long mni = LLONG_MAX;
   for(int i=0;i<n;i++){
    cin >> a[i] >> b[i] >> c[i];
     mni  = min(mni,a[i]+b[i]+c[i]);
   }
   ll l = mni;
   ll r = mni+k+1;
   while(r-l>1){
     ll mid = l+(r-l)/2;
     if(check(mid)){
         l = mid;
     }
     else {
        r = mid;
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