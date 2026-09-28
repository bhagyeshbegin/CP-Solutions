#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
                map<string,pair<int,int>> mp;
        for(int i=0;i<n;i++){
            int n1;
            string w;
            cin >> w >> n1;
            if(n1==0){
                mp[w].first++;
            }
            else {
                mp[w].second++;
            }
        }
        int ans = 0;
        for(auto it:mp){
            ans += max(it.second.first,it.second.second);
        }
        cout << ans << endl;
    }
}
