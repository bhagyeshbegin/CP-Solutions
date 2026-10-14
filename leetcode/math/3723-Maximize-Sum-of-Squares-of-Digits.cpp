class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num){
            return "";
        }
        string s;
        while(num>0){
           int minimum = min(sum,9);
            s += to_string(minimum);
            sum -= minimum;
            num--;
        }
        return s;
    }
};