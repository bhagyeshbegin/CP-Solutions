class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        
        for(int i=0;i<n-1;i++){
            int maximum  = -1;
            for(int j=i+1;j<n;j++){
              maximum = max(maximum,arr[j]);
            }
            ans.push_back(maximum);
        }
        ans.push_back(-1);
        return ans;
    }
};