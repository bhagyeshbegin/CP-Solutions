#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b;
        for(int i=0;i<n;i++){
            cin >> a[i];
            b.push_back(a[i]);
        }
        sort(b.begin(),b.end());
        int maximum = INT_MIN;
        int ans = INT_MAX;
        if(a==b){
            cout << -1 << endl;
        }
        else {
            for(int i=0;i<n;i++){
                 if(a[i]!=b[i]){
                     maximum = max(a[i]-b[0],b[n-1]-a[i]); //this tells us maximum k for which every value is movable.
                     //so every misplace element should be movable we take balance k which is minimum
                     ans = min(ans,maximum);
                 }
            }
            cout << ans << endl;
        }
    }
}