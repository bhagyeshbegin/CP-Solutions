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
   //thought completely brute force as it has 6! permutations so which can be handled
   vector<ll> a = {4,8,15,16,23,42};
   vector<ll> p(4);
   for(int i=0;i<4;i++){
    cout << "? " <<  i+1 << " " << i+2 << endl;
    cin >> p[i];
    if(p[i]==0){
        return;
    }
   }
   do{
      bool ok = true;
      for(int i=0;i<4;i++){
        if((a[i]*a[i+1])!=p[i]){
             ok = false;
             break;
        }
      }
      if(ok){
        cout << "! ";
        for(auto x:a){
            cout << x << " ";
        }
        cout << endl;
        return;
      }
   }while(next_permutation(a.begin(),a.end()));
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