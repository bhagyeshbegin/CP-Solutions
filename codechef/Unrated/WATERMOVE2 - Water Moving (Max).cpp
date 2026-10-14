#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        long long  n,k;
        cin >> n >> k;
        vector<long long> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a.rbegin(),a.rend());
        long long sum = a[0];
        for(int i=1;i<=min(n-1,k);i++){
            sum += a[i];
        }
        cout << sum << endl;
    }
}
