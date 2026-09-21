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
   ll n,k;
   cin >> n >> k;
   vector<ll> a(n);
   for(int i=0;i<n;i++){
    cin >> a[i];
   }
   sort(a.begin(),a.end());
   vector<pair<ll,ll>> p = {{a[0],1}}; //first element is choosen by arsney,value and frequency
   for(int i=1;i<n;i++){
    if(a[i]==a[i-1]){
       p.back().second++;
    }
    else {
        p.push_back({a[i],1});
    }
   }
   //we are checking for every distinct value as arsney can choose anything.
   int n1 = p.size();
   for(int i=n1-1;i>=0;i--){
   if((p[i].second)%2==0){ //if there are equal element then 
    cout << "YES" << endl;
    return;
   }
   if(i==0){
    cout << "NO" << endl;
    return;
   }
   if(p[i].first-p[i-1].first<=k){//condition for current element and previous element.
    cout << "YES" << endl;
    return;
   }
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