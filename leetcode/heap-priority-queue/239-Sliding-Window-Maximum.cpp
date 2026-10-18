class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n =nums.size();
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        ans.push_back(pq.top().first);
        for(int i=k;i<n;i++){
            //Pq doesnt let us remove arbitary element it only allows top element.So like we can remove all the elements before the top index as they are of no use.
            while(!pq.empty() && pq.top().second<=(i-k)){
               pq.pop();
            }
            pq.push({nums[i],i});
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};