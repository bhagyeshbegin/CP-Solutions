#include <bits/stdc++.h>
using namespace std;

//PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//find_by_order,order_of_key: 0 indexed
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type,less<int> , __gnu_pbds::rb_tree_tag,
__gnu_pbds::tree_order_statistics_node_update> ordered_set;
// * find_by_order(pos) -> return iterator to element at 'pos' position(at 0 indexded)
int main(){
    int n,k;
    cin >> n >> k;
    ordered_set nums;
    for(int i=1;i<=n;i++){
        nums.insert(i);
    }
    int startpos = 0;
    while(!nums.empty()){
        //find next position used circular arry
        startpos = (startpos+k)%(nums.size());
        //Output and remove the child
        auto it = nums.find_by_order(startpos);
        cout << *it << " ";
        nums.erase(it);
    }
    //T-: O(n*logn) S:O(n);
}