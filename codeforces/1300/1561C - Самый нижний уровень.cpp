#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<pair<ll,ll>> p1;
        for(int i=0;i<n;i++){
            ll k;
            cin >> k;
            ll minimumpower = 0;
            for(ll j=0;j<k;j++){
               ll x;
               cin >> x;
               minimumpower = max(minimumpower,x-j+1); //x+1>power so general formula x-j+1
            }
            p1.push_back({minimumpower,k});
        }
        sort(p1.begin(),p1.end());
         ll power = 0;
         ll ans = 0;
         for(auto it:p1){
            ll minimumpower = it.first;
            ll k = it.second;
            if(power<minimumpower){
               ans += minimumpower-power;
               power = minimumpower;
            }
             power += k;
         }
         cout << ans << endl;
    }
}

//so first took minimum power required to cross the whole cave.
//then stored minimumpower,k that is minimumpower and k which is number monster as after beating the monster heros power will be startpower+k
//sort the pair in increasing order
//so intially power 0 so if power<start1 then will do power = start1 and  ans += start1-power
//so now will just add k in power