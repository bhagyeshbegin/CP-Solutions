class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int maximum = 0;
        vector<pair<int,int>> p;
        for(int i=0;i<n;i++){
            p.push_back({nums[i],i});
        }
        sort(p.begin(),p.end());
        int minimum = p[0].second;
        for(int i=0;i<n;i++){
            maximum = max(maximum,p[i].second-minimum);
            minimum = min(minimum,p[i].second);
        }
        return maximum;
    }
};