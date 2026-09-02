#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int n1 = n/2;
        if(n==1){
            cout << 20 << endl;
        }
        else if(n==2){
            cout << 30 << endl;
        }
        else {
            cout << (n1*30)+((n-(n1*2))*20) << endl;
        }
    }
}
