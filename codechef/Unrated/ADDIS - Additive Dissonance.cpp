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
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
        }
        int maximum = 0;
        for(auto it:mp){
            maximum = max(maximum,it.second);
        }
        cout << (maximum+1)/2 << endl;
    }
}
