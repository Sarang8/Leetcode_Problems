class Solution {
public:
    
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool &flag){
        
        if(i<0 or i>=grid1.size() or j<0 or j>=grid1[0].size() or grid2[i][j] == 0){
            return ;
        }
        
        if(grid1[i][j]==0 && grid2[i][j]==1){
            flag = false;
        }
        
        grid2[i][j]=0;
        
        dfs(grid1, grid2, i-1,j,flag);
        dfs(grid1, grid2, i+1,j,flag);
        dfs(grid1, grid2, i,j-1,flag);
        dfs(grid1, grid2, i,j+1,flag);
        
    }
    
    
    
    
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int m=grid1.size();
        int n=grid1[0].size();
        
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(grid2[i][j]==1){
                    bool flag=true;
                    dfs(grid1, grid2, i,j, flag);
                    if(flag==true){
                        ans+=1;
                    }
                }
                
            }
        }
        return ans;
        
    }
};