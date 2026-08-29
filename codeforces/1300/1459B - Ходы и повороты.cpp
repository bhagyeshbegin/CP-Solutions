#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
   ll n;
   cin >> n;
   ll steps = n/2;
   if(n%2==0){
    cout << (steps+1)*(steps+1) << endl;
   }
   else {
    cout << (2*(steps+1))*(steps+2) << endl;
   }
}