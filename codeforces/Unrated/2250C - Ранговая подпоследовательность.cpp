#include <bits/stdc++.h>
using namespace std;

const int N1 = 50001;
int  n;
int l[N1 + 10], r[N1 + 10], u[N1 + 10], v[N1 + 10];

bool isit(int m){
    int j = 1;
    for(int i=1;i<=n && j<=m;i++){
      if((j<l[i] || j>r[i]) && ((m-j+1)<u[i] || (m-j+1)>v[i])){
        j++;
      }
    }
    return j==m+1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> l[i] >> r[i] >> u[i] >> v[i];
        }
        bool ok = false;
        for(int i=n;i>=1;i--){
            if(isit(i)){
                ok = true;
                cout << i << endl;
                break;
            }
        }
        if(!ok){
            cout << 0 << endl;
        }
    }
}