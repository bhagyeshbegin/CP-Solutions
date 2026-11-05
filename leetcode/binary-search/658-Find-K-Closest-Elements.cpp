class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int i = 0;
        int j = n-1;
        while(abs(j-i+1)>k){
            if(abs(arr[i]-x)<=abs(arr[j]-x)){
                j--;
            }
            else {
                i++;
            }
        }
        return vector<int>(arr.begin()+i,arr.begin()+j+1);
    }
};