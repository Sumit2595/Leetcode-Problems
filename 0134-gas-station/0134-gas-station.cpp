class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0;
        int totalCost=0;
        for(auto g:gas)
            totalGas+=g;
        for(auto c:cost)
            totalCost+=c;
        if(totalGas<totalCost)
            return -1;
        int currentGas=0;
        int n=gas.size();
        int start=0;
        for(int i=0;i<n;i++){
            currentGas+=(gas[i]-cost[i]);
            if(currentGas<0){
                currentGas=0;
                start=i+1;
            }
        }
        return start;
    }
};