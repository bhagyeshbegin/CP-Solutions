#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        vector<bool> occupied(n+1,false);
        for(int i=0;i<m;i++){
            int x;
            cin >> x;
            occupied[x] = true;
        }
        int count = 0;
        for(int i=1;i<=n && count<k;i++){
            if(!occupied[i]){
                cout << i << " ";
                count++;
            }
        }
        cout << endl;
    }
}
