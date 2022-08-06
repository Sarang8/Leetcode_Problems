class Solution {
public:
    
    
    static bool compare(vector<int>&a, vector<int>&b){
        
        // return a[1]<b[1];
        if( a[1]<b[1] or (a[1]==b[1]  && a[2]<b[2]) ){
            return true;
        }
           return false;
    }
    
    
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int n=trips.size();
        if(n==1){
            if(capacity>=trips[0][0]) return true;
            return false;
        } 
        
        sort(trips.begin(), trips.end(), compare);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        // PAIR OF [ ENDTIME, NO. OF PASSENGERS ]
        int currPassnger=0;
        
        for(int i=0; i<n; i++){
            
            while(!pq.empty() && pq.top().first<=trips[i][1]){
                currPassnger -= pq.top().second;
                pq.pop();
            }
            
            
            currPassnger += trips[i][0];
            
            if(currPassnger>capacity){
                return false;
            }

            pq.push({trips[i][2], trips[i][0]});
            
            
        }
            
        return true;
    }
};