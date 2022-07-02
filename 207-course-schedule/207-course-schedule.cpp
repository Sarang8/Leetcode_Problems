class Solution {
public:
    
    bool cycleDFS(int i, vector<int>&visited, vector<int>&DFSvisited, vector<int> adj[]){ 
        visited[i]=1;
        DFSvisited[i]=1;
        
        for(auto it:adj[i]){
            
            if(!visited[it]){
                if(cycleDFS(it, visited, DFSvisited, adj)) return true;
            }
            else if (DFSvisited[it]==1){
                    return true;
                }           
        }
        DFSvisited[i]=0;
        return false;  
    }

    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>adj[numCourses];
        for(int i=0; i<prerequisites.size(); i++) // convert edge list to adjacency list
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        } 
        
        vector<int>visited(numCourses, 0);
        vector<int>DFSvisited(numCourses,0);
        
        
        for(int i=0; i<numCourses; i++){
            
            if(!visited[i]){
                if(cycleDFS(i,visited, DFSvisited, adj)) return false;
            }
            
        }
         return true;
        
    }
};