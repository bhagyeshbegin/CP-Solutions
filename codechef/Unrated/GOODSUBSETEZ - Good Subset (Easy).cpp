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
        vector<int> freq(32,0);
        for(int i=0;i<n;i++){
            cin >> a[i];
            int count1 = 31-__builtin_clz(a[i]);
            freq[count1]++;
        }
        int ans = 1;
        for(int i=0;i<32;i++){
            ans = max(ans,freq[i]);
        }
        cout << ans << endl;
    }
}
