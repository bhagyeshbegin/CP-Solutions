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
   ll n,m;
   cin >> n >> m;
   ll k = 1;
   ll n1 = n;
   ll count5 = 0;
   ll count2 = 0;
   ll n2 = n;
   //intial loops will find how many 2s and 5s i already have.
   while(n2>0 && n2%5==0){
      n2/=5;
      count5++;
   }
   n2 = n;
   while(n2>0 && n2%2==0){
    n2/=2;
    count2++;
   }
   //how many extra 2s and 5s are required.
   while(count5<count2 && k*5<=m){
    count5++;
    k*=5;
   }
   while(count5>count2 && k*2<=m){
      count2++;
    k*=2;
   }
   while(k*10<=m){
    k*= 10;
   }
   if(k==1){
    cout << n1*m << endl;
   }
   else {
    // k can be till m.
    ll x = m/k;
    k *= x;
    cout << k*n1 << endl;
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