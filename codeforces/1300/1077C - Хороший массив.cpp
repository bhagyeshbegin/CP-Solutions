#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ll totalsum = 0;
    vector<ll> count(1e6+1,0);
    vector<ll> ans;
    for(int i=0;i<n;i++){
       totalsum += a[i];
       count[a[i]]++;
    }
    for(int i=0;i<n;i++){
        ll newsum = totalsum - a[i];
        count[a[i]]--;
        if((newsum)%2==0  && newsum/2 <= 1e6 &&   count[newsum/2]>0){  //maxnumber of array b is newsum/2
            ans.push_back(i);
        }
        count[a[i]]++;
    }
    cout << ans.size() << endl;
    for(auto it:ans){
        cout << it+1 << " ";
    }
    cout << endl;
}