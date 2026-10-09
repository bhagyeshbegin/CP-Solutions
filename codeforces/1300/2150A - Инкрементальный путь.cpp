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
   ll n,m;
   cin >> n >> m;
   string s;
   cin >> s;
   set<ll> st;
   for(int i=0;i<m;i++){
    ll x;
    cin >> x;
    st.insert(x);
   }
    ll count1 = 1;
    for(char c:s){
        //Count1 represents next position to process instead of final position.
        count1++;
        //Will skip black cells to find white cells.
        if(c=='B'){
        while(st.count(count1)){
            count1++;
        } 
    }
    //we will insert after every command
    st.insert(count1);
    if(c=='B'){
        while(st.count(count1)){
            count1++;
        }
    }
    }
    cout << st.size() << endl;
    for(auto it:st){
        cout << it << " ";
    }
    cout << endl;
}

//For A we move forward for B we find white cell and color it black for next B we prepare for next prefix.

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