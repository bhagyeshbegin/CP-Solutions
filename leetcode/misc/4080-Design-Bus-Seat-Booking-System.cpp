class BusBooking {
public:
    vector<vector<bool>> booked;
    vector<vector<int>> cost;
    int total = 0;
    int n;
    int bookedcount= 0;
    BusBooking(int n) {
        this->n = n;
        booked.assign(n+1,vector<bool>(4,false));
        cost.assign(n+1,vector<int>(4,0));
    }
    
    void toggle(string seat) {
        char ch = seat[0];
        int row = stoi(seat.substr(1));
        int index = ch-'A';
        if(booked[row][index]){
            total-= cost[row][index];
            booked[row][index] = false;
            cost[row][index] = 0;
            bookedcount--;
        }
        else {
            int time = 1;
            if(ch=='A' && booked[row][1]){
                time = 3;
            }
            if(ch=='D' && booked[row][2]){
                time = 3;
            }
            booked[row][index] = true;
            cost[row][index] = time;
            total += time;
            bookedcount++;
        }
    }
    
    int getTotalTime() {
        return total;
    }
    
    int getMinTime() {
        return bookedcount;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */