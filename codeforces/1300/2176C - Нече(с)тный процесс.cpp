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
   vector<ll> a(n);
   for(int i=0;i<n;i++){
    cin >> a[i];
   }
   vector<ll> even;
   vector<ll> odd;
   for(int i=0;i<n;i++){
    if(a[i]%2==0){
        even.push_back(a[i]);
    }
    else {
        odd.push_back(a[i]);
    }
   }
   sort(odd.rbegin(),odd.rend());
   sort(even.rbegin(),even.rend());
   int E  = even.size();
   int O = odd.size();
   vector<ll> pref(E+1,0);
   for(int i=0;i<E;i++){
    pref[i+1] = pref[i]+even[i];
   }
   for(int k=1;k<=n;k++){
     //number of odd.
     //I will always try to have 1 odd has other pair of odd will form even and will be cleared by cat.
      int q = max(1,k-E);
      //as i want only 1 odd so q must be odd
      if(q%2==0){
        q++;
      }
      //if q is more than odd avalaible so its not possible.
      if(q>O || q>k){
        cout << 0 << " ";
        continue;
      }
      //so 1odd + maximize even sum.
      int e = k-q;
      ll ans = odd[0]+pref[e];
      cout << ans << " ";
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