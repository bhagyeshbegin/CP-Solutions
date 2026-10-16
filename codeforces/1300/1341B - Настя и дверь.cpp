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
   ll n,k;
   cin >> n >> k;
   vector<ll> a(n);
   for(int i=0;i<n;i++){
    cin >> a[i];
   }
   vector<ll> peak(n+1,0);
   for(int i=1;i<n-1;i++){
    if(a[i]>a[i-1] && a[i]>a[i+1]){
        peak[i] = 1;
    }
   }
   ll i1 = 0;
   ll count = 0;
   //We are keeping on removing and adding from first window only.
   //So will compute count for it first and then keep on subtracting left and adding right in count
   for(int i=1;i<k-1;i++){
    count += peak[i];
   }
   ll maximum = count;
   for(ll left=1;left<=n-k;left++){
    //we are removing previous windows 1st element.
       count -= peak[left];
       //we are adding previous windows last element.
       count += peak[left+k-2]; //0 based indexing thats why -2.
       if(count>maximum){
        maximum  = count;
        i1 = left;
    }
   }
    cout << maximum+1 << " " << i1+1 << endl;
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