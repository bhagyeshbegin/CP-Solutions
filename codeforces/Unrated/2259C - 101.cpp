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
        int left = -1;
        int right = -1;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                if(left==-1) left = i;
                right = i;
            }
        }
        if(left==-1){
            int l1 = -1;
            int r1 = -1;
            for(int i=0;i<n;i++){
                if(a[i]==-1){
                    if(l1==-1){
                        l1 = i;
                    }
                    r1 = i;
                }
            }
            if(l1!=-1){
                for(int i=0;i<n;i++){
                    if(a[i]==-1){
                        if(i==l1 || i==r1){
                            a[i]=1;
                        }
                        else {
                            a[i] = 0;
                        }
                    }
                }
            }
        }
        else {
            for(int i=left+1;i<right;i++){
                if(a[i]==-1){
                    a[i] = 0;
                }
            }
            int l2 = -1;
            for(int i=0;i<left;i++){
                if(a[i]==-1){
                    l2 = i;
                    break;
                }
            }
            if(l2!=-1){
                for(int i=0;i<left;i++){
                    if(a[i]==-1){
                        if(i==l2){
                            a[i] = 1;
                        }
                        else {
                            a[i] = 0;
                        }
                    }
                }
            }
            int r2 = -1;
            for(int i=n-1;i>right;i--){
                if(a[i]==-1){
                    r2 = i;
                    break;
                }
            }
            if(r2!=-1){
                for(int i=right+1;i<n;i++){
                    if(a[i]==-1){
                        if(i==r2){
                            a[i] = 1;
                        }
                        else {
                            a[i] = 0;
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
}