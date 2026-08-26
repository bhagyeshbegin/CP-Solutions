#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n,target;
    cin >> n >> target;
    vector<pair<ll,ll>> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(),a.end());
    for(ll i=0;i<n-3;i++){
        for(ll j=i+1;j<n-2;j++){
            ll s = j+1;
            ll e = n-1;
            while(s<e){
                ll sum = a[i].first+a[j].first+a[s].first+a[e].first;
                if(sum==target){
                    cout << a[i].second << " " << a[j].second << " " << a[s].second << " " << a[e].second << endl;
                    return 0;
                }
                else if(sum<target){
                    s++;
                }
                else {
                    e--;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}