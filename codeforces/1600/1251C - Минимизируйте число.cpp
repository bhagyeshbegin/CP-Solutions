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
   string n1;
   cin >> n1;
   string even = "";
   string odd = "";
   string ans = "";
   ll i1 = 0;
   ll i2 = 0;
   for(int i=0;i<n1.length();i++){
     if((n1[i]-'0')%2==0){
        even += n1[i];
     }
     else {
        odd += n1[i];
     }
   }
   while(i1<even.length() && i2<odd.length()){
       if((even[i1]-'0')<(odd[i2]-'0')){
         ans += even[i1];
         i1++;
       }
       else {
        ans += odd[i2];
        i2++;
       }
   }
   //Remaining elements
   while(i1<even.length()){
    ans += even[i1];
    i1++;
   }
   while(i2<odd.length()){
    ans += odd[i2];
    i2++;
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