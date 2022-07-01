class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        
        int TotalGas=0;
        int TotalCost=0;
        for(int i=0; i<n; i++){
            TotalGas+=gas[i];
            TotalCost+=cost[i];
        }
 
        if(TotalGas<TotalCost){
            return -1;
        }
        
        int CurrentGas=0;
        int start=0;
        for(int i=0; i<n; i++){
            CurrentGas+=gas[i]-cost[i];
            if(CurrentGas<0){
                start=i+1;
                CurrentGas=0;
            } 
        }
        
        return start;  
    }
};