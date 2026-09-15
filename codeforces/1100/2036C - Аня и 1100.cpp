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

bool check1100(string &s,ll i5){
    if(i5<0){
        return false;
    }
    if(i5>(s.length())-3){
        return false;
    }
    return s[i5]=='1' && s[i5+1]=='1' && s[i5+2]=='0' && s[i5+3]=='0';
}

void solve(ll test){
   string s;
   cin >> s;
   int n = s.length();
   ll count = 0;
   for(int i=0;i<n;i++){
    if(check1100(s,i)){
         count++;
    }
   }
   int q;
   cin >> q;
   while(q--){
    ll c,v;
    cin >> c >> v;
    c--;
    //before changes
    for(int i2=c-3;i2<=c;i2++){
       if(check1100(s,i2)){
        count--;
       }
    }
    //change
    s[c] = char('0'+v);
    //after changes
    for(int i3=c-3;i3<=c;i3++){
        if(check1100(s,i3)){
            count++;
        }
    }
    if(count>0){
        cout << "YES" << endl;
    }

    else {
        cout << "NO" << endl;
    }
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