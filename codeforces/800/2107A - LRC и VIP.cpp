#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int maximum = *max_element(a.begin(),a.end());
        int minimum = *min_element(a.begin(),a.end());
        if(minimum==maximum){
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            for(int i=0;i<n;i++){
            if(a[i]!=maximum){
                cout << 1 << " ";
            }
            else {
                cout << 2 << " ";
            }
        }
        cout << endl;
    }
    }
}