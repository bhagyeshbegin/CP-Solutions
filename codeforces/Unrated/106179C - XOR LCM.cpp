#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int t;
    cin >> t;
    while(t--){
        ll  c;
        cin >> c;
        //Assumed that a=c.
        //so the b xor c = c + lcm(b,c)
        //b should be multiple of c. so we can assume b = 2c
        ll a = c;
        ll b = 2*c;
        //now we can check for 2c,4c,8c,....
        for(ll k=1;k<=60;k++){
            b = c*(1<<k);
            //now we want b xor c = b+c
            //so if there are common bits there would be carry so sum and xor can be same.
            //so we want opposite bits so will check this by & as it will give 0
            if((b&c)==0){
                break;
            }
        }
        cout << a << " " << b << endl;
    }
}