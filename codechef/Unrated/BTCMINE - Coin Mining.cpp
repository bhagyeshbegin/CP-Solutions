#include <bits/stdc++.h>
using namespace std;

void solve(){
        int x,y;
        cin >> x >> y;
        vector<int> dp(1005,INT_MIN);
        dp[0] = 0;
        for(int day=1; ;day++){
            vector<int> newdp(1005,INT_MIN);
            for(int k=0;k<=day-1;k++){
                newdp[k] = max(newdp[k],dp[k]+(y*k*k));
                newdp[k+1] = max(newdp[k+1],dp[k]-x+(y*(k+1)*(k+1)));
            }
            dp = newdp;
            for(int k=0;k<=day;k++){
                if(dp[k]>0){
                    cout << day << endl;
                    return;
                }
            }
        }
    }

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
   solve();
	}
}
