class Solution {
public:
    
//     void toposort(int i, vector<int>adj[], vector<int>&visi, stack<int>&st){
        
//         visi[i]=1;
//         for(auto it:adj[i]){
//             if(!visi[it]){
//                 toposort(it, adj, visi, st);
//             }   
//         }
//         st.push(i);
//         //cout<<st.top();
//     }
    
    
    
     bool DetectcycleDFS(int i, vector<int>&visited, vector<int>&DFSvisited, vector<int> adj[]){ 
        visited[i]=1;
        DFSvisited[i]=1;
        
        for(auto it:adj[i]){
            
            if(!visited[it]){
                if(DetectcycleDFS(it, visited, DFSvisited, adj)) return true;
            }
            else if (DFSvisited[it]==1){
                    return true;
                }           
        }
        DFSvisited[i]=0;
        return false;  
    }

    
    
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            
//         vector<int> adj[numCourses];
        
//         for(int i=0; i<prerequisites.size(); i++){
//             adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
//         }
        
//         vector<int>visi(numCourses, 0);
//         vector<int>DFSvisi(numCourses, 0);
//         stack<int>st;
//         vector<int>topo;
        
//         for(int i=0; i<numCourses; i++){
//             if(!visi[i]){
                
//                 if(DetectcycleDFS(i, visi,DFSvisi,adj)==false){
//                    toposort(i, adj, visi, st); 
//                 }
//                 else{
//                     return topo;
//                 }
//             }
//         }
//         cout<<st.size();   
//         while(!st.empty()){
//             topo.push_back(st.top());
//             st.pop();  
//         }
//         reverse(topo.begin(), topo.end());
//         return topo;
//     }
        
        
        
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
            
        vector<int> adj[numCourses];
        
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
            
        vector<int>indegree(numCourses,0);
        queue<int>q;
        vector<int>visi(numCourses, 0);
        vector<int>DFSvisi(numCourses, 0);
        vector<int>topo;
            
        for(int i=0; i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i=0; i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
            
        for(int i=0; i<numCourses; i++){
            if(!visi[i]){ 
                if(DetectcycleDFS(i, visi,DFSvisi,adj)==true)
                    return topo;
            }
        }
            
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        reverse(topo.begin(), topo.end());
        return topo;
            
        }
};