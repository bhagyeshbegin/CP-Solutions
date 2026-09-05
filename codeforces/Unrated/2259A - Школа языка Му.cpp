#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string a;
        cin >>a;
        int count = 0;
        for(int i=0;i<n;i+=k){
            bool zero = false;
            for(int j=i;j<i+k;j++){
                if(a[j]=='0'){
                    zero = true;
                    break;
                }
            }
            if(!zero){
                count++;
            }
        }
        cout << count << endl;
    }
}