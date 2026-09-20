#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,t;
    cin >> n >> t;
    while(t--){
        int k; //which position zero asked for
        cin >> k;
        int s = 1;
        int e = n;
        while(s<e){
            int mid = (s+e)/2;
            cout << "? " << s << " " << mid << endl;
            int sum;
            cin >> sum;
            if(sum==-1){
                return 0;
            }
            int countzeros = (mid-s+1)-sum; //number of zeros between s and mid
            //if kth zero is in left half
            //if countzero gives enough zeros which are greater than k so it will lie in left half
            if(countzeros>=k){
                e = mid;
            } 
            else {
                //we want zeros from left so when we move right the zeros from left are of no use.
                k = k-countzeros;//by doing this will geet position of kth zero from mid+1.
                s = mid+1;
            }
        }
          cout << "! " << s << endl;
    }
}