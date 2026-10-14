#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
   int t;
   cin >> t;
   while(t--){
       int n,k;
       cin >> n >> k;
       vector<int> a(n);
       for(int i=0;i<n;i++){
           cin >> a[i];
       }
       sort(a.begin(),a.end());
       cout << max(a[n-1],a[0]+a[1]) << endl;
   }
}
