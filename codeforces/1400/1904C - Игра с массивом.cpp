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
       ll ans = a[0];
   if(k>=3){
       cout << 0 << endl;
       return;
   }
   else if(k==1){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            ans = min(ans,a[i]-a[j]);
        }
    }
    cout << ans << endl;
    return;
   }
   else if(k==2){
       for(int i=1;i<n;i++){
          ans = min(ans,a[i]-a[i-1]); //minimum value after 1st operation
       for(int j=0;j<i;j++){
          ll p1 = a[i]-a[j]; //1st operation
          //now for minimum i need to find the element 
          //which first greater than p1 ans last smaller than p1
          //so  will use lower bound
          ll it = lower_bound(a.begin(),a.end(),p1)-a.begin();
          //first greater than p1
           if(it<n){
             ans = min(ans,a[it]-p1);
           }
           //now for last smaller than p1
           if(it>0){
            it--;
            ans = min(ans,p1-a[it]);
           }
       }
       }
       cout << ans << endl;
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