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
   //first for odd elements make them even
   for(int i=0;i<n;i++){
    while(a[i]%2==1){
       a[i] += (a[i]%10);
    }
   }
   //something new to check whether all have bacome equal or not
   if(count(a.begin(),a.end(),a[0])==n){
    cout << "YES" << endl;
    return;
   }
   //now what it end at zero
   for(int i=0;i<n;i++){
    if(a[i]%10==0){
        cout << "NO" << endl;
        return;
    }
   }
   //now for  even elements.
   //the loop of +2 +4 +8 +6 keeps on repeating in cycle
   //so there is difference of 20
   for(int i=0;i<n;i++){
    while(a[i]%10!=2){
        a[i] += (a[i]%10);
    }
    a[i] %= 20;
   }
   if(count(a.begin(),a.end(),a[0])==n){
    cout << "YES" << endl;
   }
   else {
    cout << "NO" << endl;
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