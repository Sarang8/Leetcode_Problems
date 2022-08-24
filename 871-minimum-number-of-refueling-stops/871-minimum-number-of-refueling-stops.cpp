class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n=stations.size();
        int maxReach=startFuel;
        int count=0;
        priority_queue<int>pq;
        
        int ind=0;
        
        while(target>maxReach){
            
            while(ind<n && maxReach>=stations[ind][0]){
                pq.push(stations[ind][1]);
                ind++;
            }
            
            if(pq.empty()) return -1;
            
            maxReach+=pq.top();
            pq.pop();
            count++;
        } 
        
        return count;
    }
};