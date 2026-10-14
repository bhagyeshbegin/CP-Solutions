#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        int minimum = INT_MAX;
        if(n<=2){
            cout << 0 << endl;
        }
        else {
              cout << min(a[n-1]-a[1],a[n-2]-a[0]) << endl;
        }
    }
}
