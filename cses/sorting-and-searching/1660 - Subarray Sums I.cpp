#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
   ll n,k;
   cin >> n >> k;
   vector<ll> a(n);
   for(int i=0;i<n;i++){
    cin >> a[i];
   }
   ll left = 0;
   ll count = 0;
    ll sum = 0;
   for(int right=0;right<n;right++){
    sum += a[right];
     while(sum>k){
      sum -= a[left];  //imp
      left++;
     }
     if(sum==k){
        count++;
     }
   }
   cout << count << endl;
}