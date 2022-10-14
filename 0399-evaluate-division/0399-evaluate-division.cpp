class Solution {
public:
    
    double dfs(string startNode, string EndNode, unordered_map<string,unordered_map<string,double>>& adj, set<string>&visi){
        
        if(adj[startNode].find(EndNode)!=adj[startNode].end()){
            return adj[startNode][EndNode];
        }
            
        visi.insert(startNode);
        
        for(auto it:adj[startNode]){
            if(visi.find(it.first)==visi.end()){
                double t1 = dfs(it.first, EndNode, adj, visi);
                if(t1!=-1.0){
                   return t1*it.second; 
                }        
            }
        }
        return -1.0; 
    }
    
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n=equations.size();
        unordered_map<string, unordered_map<string, double>>adj;
        
        for(int i=0;i<n;i++){
            adj[equations[i][0]].insert({equations[i][1], values[i]});
            adj[equations[i][1]].insert({equations[i][0], 1.0/values[i]});
        }
        
        vector<double>ans;
        int m=queries.size();
        for(int i=0;i<m;i++){
            
            set<string>visi;
            double temp=dfs(queries[i][0], queries[i][1], adj, visi);
            //cout<<temp<<endl;
            ans.push_back(temp); 
        }
        
        return ans;
    }
};