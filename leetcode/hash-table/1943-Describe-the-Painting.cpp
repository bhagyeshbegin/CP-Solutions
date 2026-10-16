class Solution {
public:
using ll = long long;
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int n = segments.size();
        map<ll,ll> mp;
        for(int i=0;i<n;i++){
        mp[segments[i][0]] += segments[i][2];
        mp[segments[i][1]] -= segments[i][2];
        }
        ll sum = 0;
        ll prev = 0;
        vector<vector<ll>> ans;
        for(auto it:mp){
            ll current = it.first;
            if(sum!=0 && current>prev){
                ans.push_back({prev,current,sum});
            }
            sum += it.second;
            prev = current;
        }
        return ans;
    }
};