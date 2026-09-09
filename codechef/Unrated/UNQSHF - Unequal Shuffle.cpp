#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
   int t;
   cin >> t;
   while(t--){
       int n;
       cin >> n;
       string a;
       cin >> a;
       string b;
       cin >> b;
       int a1 = count(a.begin(),a.end(),'a');
       int b1 = count(b.begin(),b.end(),'a');
       if(a1==n-b1){
           cout << "YES" << endl;
       }
       else {
           cout << "NO" << endl;
       }
   }
}
