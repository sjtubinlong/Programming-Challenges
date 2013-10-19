class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = gas.size();
        int tank = 0;
        int total = 0;
        int ret = 0;
        for( int i = 0; i < n; ++i ){
            total += (gas[i]-cost[i]);
            tank += (gas[i]-cost[i]);
            if( total < 0 ){
                ret = (i+1)%n;
                total = 0;
            }
        }
        return tank < 0 ?-1:ret;
    }
};