#include <bits/stdc++.h>
using namespace std;

using ll = long long;

//PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//find_by_order,order_of_key: 0 indexed
typedef __gnu_pbds::tree<pair<ll,int>, __gnu_pbds::null_type,less<pair<ll,int>> , __gnu_pbds::rb_tree_tag,
__gnu_pbds::tree_order_statistics_node_update> ordered_set;

int main(){
   ll n,k;
   cin >> n >> k;
   //We will use pbds here as we want sorted window + median which will require indexes so pbds will help.
   ordered_set nums;
   vector<ll> a(n+1);
   for(int i=1;i<=n;i++){
      cin >> a[i];
   }
   vector<ll> ans;
   //We will precompute first windows median and the in which will keep removing previous windows first element and will insert new windows latest element.
   for(int i=1;i<=k;i++){
        nums.insert({a[i],i});
   }
   ans.push_back(nums.find_by_order((k-1)/2)->first);
   //now will go to next window.
   for(int i=k+1;i<=n;i++){
    nums.erase({a[i-k],i-k});
    nums.insert({a[i],i});
    ans.push_back(nums.find_by_order((k-1)/2)->first);
   }
   for(int  i=0;i<ans.size();i++){
    cout << ans[i] << " ";
   }
   cout << endl;
}