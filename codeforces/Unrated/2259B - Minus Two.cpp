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
        int oddcount = 0;
        int c0 = 0;
        int c1  = 0;
       map<int,int> mp;
        for(int i=0;i<n;i++){
            if(a[i]%2!=0){
               oddcount++;
            }
            //0,2 ke cycle
            else {
               int half = a[i]/2;
               if(half%2==0){
                 c0++;
               }
               else {
                c1++;
               }
            }
        }
        cout << max(oddcount,max(c0,c1)) << endl;
    }
}