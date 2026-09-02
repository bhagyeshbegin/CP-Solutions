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
        int n1 = n-k;
        int sum = 0;
        for(int i=0;i<n1;i++){
            sum += a[i];
        }
        int ans = sum;
        for(int i=n1;i<n;i++){
            sum += a[i]; 
            sum -= a[i-n1];
            ans = max(ans,sum);
        }
        cout << ans << endl;
    }
}
