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
   string s;
   cin >> s;
   vector<ll> pref(n+1,0);
   for(int i=1;i<=n;i++){
    if(s[i-1]=='('){
        pref[i] = pref[i-1]+ 1;
    }
    else {
        pref[i] = pref[i-1]-1;
    }
   }
   //Not a regular sequence
   if(pref[n]!=0){
     cout << -1 << endl;
     return;
   }
   //regular sequence with no negative.
   ll minimum = *min_element(pref.begin(),pref.end());
   if(minimum==0){
    cout << 1 << endl;
       for(int i=1;i<=n;i++){
        cout << 1 << " ";
       }
       cout << endl;
       return;
   }
   ll maximum = *max_element(pref.begin(),pref.end());
   //after doing reverse this becomes regular.
   if(maximum==0){
    cout << 1 << endl;
    for(int i=1;i<=n;i++){
        cout << 1 << " ";
    }
    cout << endl;
    return;
   }
   //for positive 2
   //for negative 1 
   //for 0 we need to check previous according to that.
   vector<ll> ans(n+1);
   for(int i=1;i<=n;i++){
    if(pref[i]>0){
        ans[i] = 1;
    }
    else if(pref[i]<0){
        ans[i] = 2;
    }
    else {
        if(pref[i-1]<0){
            ans[i] = 2;
        }
        else {
            ans[i] = 1;
        }
    }
   }
   cout << 2 << endl;
   for(int i=1;i<=n;i++){
    cout << ans[i] << " ";
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