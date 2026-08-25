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
    for(ll i=0;i<n;i++){
        ll left = i+1;
        ll right = n-1;
        while(left<right){
            ll sum = a[i].first+a[left].first+a[right].first;
            if(sum==target){
              cout << a[i].second << " " << a[left].second << " " << a[right].second << endl;
              return 0;
    }
    else if(sum<target){
        left++;
    }
    else {
        right--;
    }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}