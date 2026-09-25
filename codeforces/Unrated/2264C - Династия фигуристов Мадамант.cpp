#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Constants
const int MOD = 998244353;

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
   ll n;
   cin >> n;
   vector<ll> b(n);
   for(int i=0;i<n;i++){
    cin >> b[i];
   }
   sort(b.begin(),b.end());
   vector<ll> b1(n+1,0); //this for b[j] summation from i=1 to n-1
   for(int i=n-1;i>=0;i--){
    b1[i] = b1[i+1] + b[i];
   }
   //now for ways
   //before i so will use prefix
   vector<ll> pref(n,1);
   for(int i=0;i<n-1;i++){
      pref[i+1] = pref[i]*(n-i-1)%MOD;
   }
   //after i so will use sufffix
   vector<ll> suff(n+1,1);
   for(int i=n-2;i>=0;i--){
      suff[i] = suff[i+1]*(n-i-1)%MOD;
   }
   ll ans = 0;
   for(int i=0;i<n-1;i++){
      ll a1 = b1[i+1]-(n-i-1)*b[i];
      ll ways = pref[i]*suff[i+1]%MOD;
      ans  = (ans+(a1%MOD)*ways)%MOD;
   }
   cout << ans << endl;
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