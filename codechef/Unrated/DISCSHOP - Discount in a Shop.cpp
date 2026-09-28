#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int pos = -1;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]>s[i+1]){
                pos = i;
                break;
            }
        }
        if(pos==-1){
            pos = s.length()-1;
        }
        s.erase(pos,1);
        int s1 = 0;
        while(s1<s.length()-1 && s[s1]=='0'){
            s1++;
        }
        cout << s.substr(s1) << endl;
    }
}
