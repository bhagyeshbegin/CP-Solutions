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

ll l[200000];
ll r[200000];

bool check(int n1,int jump){
    ll currentjumpbegin = 0;
    ll currentjumpend = 0;
    for(int i=1;i<=n1;i++){
        //it can left/right so we can move from L-jump to R+jump
        currentjumpbegin -= jump;
        currentjumpend += jump;

        ll maxreach = max(currentjumpbegin,l[i]);
        ll minreach = min(currentjumpend,r[i]);
        //if  they intersect  then they will lie between l[i],r[i]
        if(maxreach>minreach){
            return false;
        }
        //update curent positions.
        currentjumpbegin = maxreach;
        currentjumpend = minreach;
    }
    return true;
}


void solve(ll test){
   ll n;
   cin >> n;
   for(int i=1;i<=n;i++){
    cin >> l[i] >> r[i];
   }
   int low = 0;
   int high = 1e9;

   while(low<high){
    int mid = (low+high)/2;
       if(check(n,mid)){
           high = mid; //will find better smaller
       }
       else {
        low = mid+1; //will find larger
       }
   }
   cout << low << endl;
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