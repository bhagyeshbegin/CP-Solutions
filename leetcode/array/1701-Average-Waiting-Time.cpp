class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double n = customers.size();
        double totalwaiting = 0;
        double current = 0;
        for(auto it:customers){
            double arrival = it[0];
            double timeprep = it[1];
            if(current<=arrival){
                totalwaiting += timeprep;
                current = arrival + timeprep;
            }
            else {
                totalwaiting += (current-arrival+timeprep);
                current += timeprep;
            }
        }
        return totalwaiting/n;
    }
};