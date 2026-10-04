class Solution {
public:
    int minRotations(string s) {
        int result = 0;
        int last = 0;
        for(char c:s){
            int current = c-'0';
            int diff = abs(current-last);
            result += min(diff,10-diff);
            last = current;
        }
        return result;
    }
};