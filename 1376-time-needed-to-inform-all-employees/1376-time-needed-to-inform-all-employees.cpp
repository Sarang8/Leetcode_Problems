class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        //int m=manager.size();
        vector<int>adj[n+1];
        
        for(int i=0;i<n;i++){
            if(manager[i]==-1) continue;
            adj[manager[i]].push_back(i);
        }
        
        queue<pair<int, int>>q;
        q.push({headID, informTime[headID]});
        int maxi=informTime[headID];
        
        while(!q.empty()){
            
            auto p=q.front();
            q.pop();
            int node=p.first;
            int time = p.second;

            for(auto it:adj[node]){
                q.push({it, time+informTime[it]});

                maxi = max(maxi, time+informTime[it]);
                //cout<<maxi<<endl;
                
            }
        }
        return maxi;
    }
};