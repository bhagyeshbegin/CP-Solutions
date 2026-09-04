#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,W;
        cin >> n >> W;
        vector<ll> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        map<ll,ll,greater<ll>> mp;  //desceding order
        for(int i=0;i<n;i++){
            mp[a[i]]++;
        }
        ll h = 0;
        ll usedbox = 0;
        while(usedbox<n){
            ll sum = W;
            for(auto &it:mp){
              while(it.first<=sum && it.second>0){
                sum -= it.first;
                it.second--;
                usedbox++;
              }  
            }
            h++;
        }
        cout << h << endl;
    }
}

// like we are filling row by row pahele apan jo largest hai unko bhar le rahe hai phir uske baad space bachege uske hisaab se isliye we are using map in descending order.