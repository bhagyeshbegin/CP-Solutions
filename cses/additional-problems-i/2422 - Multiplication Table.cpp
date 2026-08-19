#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool helper(ll mid,ll n1){
     ll count = 0;
     for(ll row=1;row<=n1;row++){
        count += min(n1,mid/row); //how many elements in that particular row are less than equal to mid
     }
     return count>=((n1*n1)+1)/2;  //condition -: mid>=((n*n)+1)/2
}

int main(){
    ll n;
    cin >> n;
    ll low = 1;
    ll high = n*n;
    ll ans = -1;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(helper(mid,n)){
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    cout << ans << endl;
}