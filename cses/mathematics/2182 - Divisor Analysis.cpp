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

ll inverse(ll a){
   return  modpow(a,MOD-2);
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
    ll n;
    cin >> n;
    vector<pair<ll,ll>> pfactors(n);
    for(int i=0;i<n;i++){
        cin >> pfactors[i].first >> pfactors[i].second;
    }
    //number of divisors-: (a+1)*(b+1)....  we included 0 also so thats why +1
    ll ans = 1;
    for(int i=0;i<n;i++){
         ans = ans * (pfactors[i].second+1)%MOD;
    }
    
    //sum of divisors-: so in this we use sum formula of gp and also did +1 as we use 0 as exponent so formula becomes
    //sum = pi(qi^b[i]-1)/b[i]-1.
    ll ans1 = 1;
    for(int i=0;i<n;i++){
        ll numerator = (modpow(pfactors[i].first,pfactors[i].second+1)-1+MOD)%MOD;
        ll denominator = inverse(pfactors[i].first-1);

        ll gp = numerator*denominator%MOD;
        ans1 = ans1 *(gp)%MOD;
    }
    //product of divisors-: so p^0*p^1..... so it becomes p^0+1=2...a so natural sum formula
    //p^a*(a+1)/2 similary for q. so now we will use some common terms of q^b in p and vice versa
    //so formula becpome p^(b+1)*(a*(a+1)/2)*q^(a+1)*(b*(b+1)/2)....
    ll ans2 = 1;
    ll num = 1; //it will store the powers of prevvious prime like (a+1)(b+1)....
    for(int i=0;i<n;i++){
        ll a = pfactors[i].second;
        //previous prime need current prime
        ans2 = modpow(ans2,a+1);
        ll expo;
        if(a%2==0){
            //we will divide a first
            expo = (a/2)*(a+1);
        }
        else {
            //we will divide a+1
            expo = (a)*((a+1)/2);
        }
        //current prime : p^(a*(a+1)/2)
        ll base = modpow(pfactors[i].first,expo);
        //multiply by previous powers
        ll val = modpow(base,num);

        ans2 = ans2*val % MOD;
        //save current a+1 for fututure use.
        num = num*(a+1) % (MOD-1);
    }
    cout << ans << " " << ans1 << " " << ans2 << endl;
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