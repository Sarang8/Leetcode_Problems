class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i, j});
                }
            }
        }
        
        if(q.size()==n*m) return -1;
        
        vector<int>dx={0, 0, 1, -1};
        vector<int>dy={1, -1, 0, 0};
        
        int dist=0;
        
        while(!q.empty()){
            
            int size=q.size();
            dist++;
            
            for(int i=0;i<size;i++){
                auto p=q.front();
                int x=p.first;
                int y=p.second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int nx = dx[i]+x;
                    int ny = dy[i]+y;
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==0){
                        q.push({nx, ny});
                        grid[nx][ny]=1;
                    }
                }
            }
        }
        
        return dist-1;
        
    }
};