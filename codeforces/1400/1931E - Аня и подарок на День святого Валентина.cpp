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
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<ll> trailing(n);
    ll totaldigit = 0;
    //Anna can remove trailing zeros after reversal it can change totaldigit count.
    //Sasha concatenates those two numbers it cant change the totaldigit count.
    for(int i=0;i<n;i++){
        while(a[i]>0 && a[i]%10==0){
           trailing[i]++;
           a[i] /= 10;
           totaldigit++;
    }
    while(a[i]>0){
        totaldigit++;
        a[i]/=10;
    }
    }
    //if we are thinking by annas pov we want number as small as possible so she will try to remove maximum trialing zeros
    sort(trailing.rbegin(),trailing.rend());
    //First Anna reverses then sasha immediately concatenates so it goes alternating.
    for(int i=0;i<n;i+=2){
        totaldigit-=trailing[i];
    }
    if(totaldigit>m){
        cout << "Sasha" << endl;
    }
    else {
        cout << "Anna" << endl;
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