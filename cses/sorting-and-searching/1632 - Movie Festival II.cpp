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
   vector<pair<ll,ll>> movie(n);
   for(auto &[a,b]:movie){
    cin >> a >> b;
   }
   sort(movie.begin(),movie.end(),[](auto &x,auto &y){
    return x.second<y.second;
   });
   multiset<ll> freetime; // this will store the end time
   for(int i=0;i<k;i++){
        freetime.insert(0);
   }
   ll ans = 0;
   for(auto[start,end]:movie){
     auto it = freetime.upper_bound(start); // this will give first element strictly greater than start in multiset
     if(it == freetime.begin()){
        continue;
     }
     it--; // this will give last element less than  or equalstart in multiset where we accomodate person to watch movie
     freetime.erase(it);
     freetime.insert(end);  //inset the end of movie
     ans++;   // increment the movie count
   }
   cout << ans << endl;
}




// ---- MAIN -----
int main(){
    fast_io
    long long t = 1;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}