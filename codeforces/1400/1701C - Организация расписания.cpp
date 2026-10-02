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

bool check(ll time,vector<ll>& freq,ll m){
    int n = freq.size();
    ll completime = 0;
      for(int i=1;i<n;i++){
       //if workers has some extra time he can complete his own proficient taks + non proficient task which  take 2 hours.
       if(freq[i]<=time){
          completime += freq[i] + (time-freq[i])/2;
       }
       else {
          completime += time;
       }
      }
     return completime>=m;   //will worker be able to complete m task in t time.
}


void solve(ll test){
   ll n,m;
   cin >> n >> m;
   vector<ll> a(m);
   for(int i=0;i<m;i++){
    cin >> a[i];
   }
    vector<ll> freq(n+1,0);
    for(int i=0;i<m;i++){
        freq[a[i]]++;
    }
    ll s = 1;
    ll e = 2*m;   //worst case time completion
    while(s<e){
        ll mid = s+(e-s)/2;
        if(check(mid,freq,m)){
            e = mid;   //if it can complete m work so will go for better answer.
        }
        else {
            s = mid+1;   
        }
    }
    cout << s << endl;
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