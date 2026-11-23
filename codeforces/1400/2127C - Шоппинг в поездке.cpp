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
//Main idea of this question if the intersection hoga Bob maximize nahi kar payega aur agar intersection hoga toh bob increment kar payega 
//so Alice ko minimize karna hai so woh intersection wale index degi so Bob increment nahi kar paaaye but
//agar non intersection hai saare so woh jisme minimum rahega (b1-a2) rahega woh index legi jo adjcent hi rahege.

// ----- SOLVE ------

void solve(ll test){
  ll n,k;
  cin >> n >> k;
  vector<pair<ll,ll>> v(n);
  for(int i=0;i<n;i++){
    cin >> v[i].first;
  }
  for(int i=0;i<n;i++){
    cin >> v[i].second;
  }
  for(int i=0;i<n;i++){
    if(v[i].second<v[i].first){
        swap(v[i].first,v[i].second);
    }
  }
  //a[i]<=b[i]
  sort(v.begin(),v.end());
  ll ans = 0;
  for(int i=0;i<n;i++){
  ans += abs(v[i].second-v[i].first);
  }
  ll minimum = LLONG_MAX;
  for(int i=0;i<n-1;i++){
    if(v[i+1].first<=v[i].second){
        cout << ans << endl;
        return;
    }
    minimum = min(minimum,v[i+1].first-v[i].second);
  }
  cout << ans+2*(minimum) << endl;
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