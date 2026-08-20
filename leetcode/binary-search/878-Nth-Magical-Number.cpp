class Solution {
public:
    long long lcm(long long a,long long b){
        return 1ll*a*b/gcd(a,b);
    }
    long long mod = 1e9+7;
    int nthMagicalNumber(int n, int a, int b) {
        long long s = min(a,b);
        long long e = 1e18;
        long long  ans = 0;
        while(s<=e){
            long long mid = s+(e-s)/2;
            long long n1 = (mid/a)+(mid/b)-(mid/lcm(a,b));
            if(n1<n){
                s = mid+1;
            }
            else {
                ans = (mid)%mod;
                e = mid-1;
            }
        }
        return ans;
    }
};