#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9+7;

struct matrix {
    ll a[2][2];
};

matrix multiplication(matrix A,matrix B){
   matrix C{};
   for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        for(int k=0;k<2;k++){
            C.a[i][j] += A.a[i][k]*B.a[k][j];
            C.a[i][j] %=mod;
        }
    }
   }
   return C;
}

matrix power(matrix A,ll n){
    matrix result{};
    result.a[0][0] = 1;
    result.a[1][1] = 1;

    while(n>0){
        if(n&1){
            result = multiplication(result,A);
        }
        A = multiplication(A,A);
        n/=2;
    }
    return result;
}

int main(){
    ll n;
    cin >> n;
    matrix A{};
    A.a[0][0] = 1;
    A.a[0][1] = 1;
    A.a[1][0] = 1;
    A.a[1][1] = 0;

    matrix ans = power(A,n);

    cout << ans.a[0][1] << endl;
}