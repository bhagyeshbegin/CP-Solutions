class Solution {
public:
    bool check(long long mid1,vector<int>& time,int trips){
        long long sum = 0;
        for(int i=0;i<time.size();i++){
            sum += (mid1/time[i]);
        }
        return sum>=trips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long n = time.size();
        long long low = 1;
        long long high = 1e14;
        while(low<=high){
            long long mid = (low+high)/2;
            if(check(mid,time,totalTrips)){
               high = mid-1;
            }
            else {
                low  = mid+1;
            }
        }
        return low;
    }
};