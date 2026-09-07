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
   vector<pair<ll,ll>> block;
   for(int x:a){
    if(block.empty() || block.back().first!=x){
        block.push_back({x,1});
    }
    else {
          block.back().second++;
    }
   }
   ll ans = 0;
   while(block.size()>0){
    bool hasone = false; // will only start with the block which has freq = 1 as it is necessary duplication only increased the freq of elements not decrement
    for(auto[value,freq]:block){
        if(freq==1){
            hasone = true;
            break;
        }
    }
    ll currl = 0;
    for(auto[value,freq]:block){
        currl += freq;
    }
    ll n1 = block.size();  //n1 is how many values have frequcny >0 so that much number of elements will be +1 after duplication.
    if(hasone && currl<=k && (k-currl)%(n1)==0){ //(k-currl)% n1 if it is zero will tell us that can we reach k after adding the n1 is the current length.
        ans++;
    }
   vector<pair<ll,ll>> next;// will store the updated freq vector after deleteing
   for(auto[value,freq]:block){
    freq--;
    if(freq==0){
        continue;
    }
    // like if in any case the any blocks fre become zero so we can merge the two block which have same value
    if(!next.empty() && next.back().first==value){
        next.back().second += freq;
    }
    else {
        next.push_back({value,freq});
    }
   }
   block  = next;  // upadte;
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