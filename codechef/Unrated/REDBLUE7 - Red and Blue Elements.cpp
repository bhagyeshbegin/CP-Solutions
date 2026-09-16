#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    long long t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        long long total  = 0;
        for(int i=0;i<n;i++){
            total += a[i];
        }
        long long ans = 0;
        sort(a.begin(),a.end());
        vector<long long> pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1] = pref[i]+a[i];
        }
        for(int i=0;i<=n;i++){
            long long rsum = pref[i];
            long long value = (rsum*(n-i)) + ((total-rsum)*i);
            ans = max(ans,value);
            rsum = total-pref[n-i];
            value = (rsum*(n-i)) + ((total-rsum)*i);
            ans = max(ans,value);
        }
        cout << ans << endl;
    }
}
