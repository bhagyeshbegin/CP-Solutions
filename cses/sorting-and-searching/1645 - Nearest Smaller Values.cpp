#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    stack<ll> st;
    vector<ll> ans(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]>=a[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = 0;
        }
        else {
            ans[i] = st.top()+1;
        }
        st.push(i);
    }
    for(auto it:ans){
        cout << it << " ";
    }
    cout << endl;
}
//monotonic stack