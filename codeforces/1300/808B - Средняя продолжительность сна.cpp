#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    double n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ll left = 0;
    double total = 0;
    ll sum = 0;
    double length = n-k+1;
    for(ll right=0;right<n;right++){
        sum += a[right];
        while(right-left+1>k){
            sum -= a[left];
            left++;
        }
        if(right-left+1==k){
            total += sum;
        }
    }
    cout << fixed << setprecision(6);
    cout << total/length << endl;
}