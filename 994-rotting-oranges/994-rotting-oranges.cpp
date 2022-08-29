class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>rotten;
        int days=0, cnt=0;
        int total = 0;
        int m = grid.size(); int n = grid[0].size(); 
        
        
        for (int i=0; i<m; i++){
            for(int j=0; j<n; j++){ 
                if(grid[i][j]!=0)  total++;
                
                if(grid[i][j]==2){
                   rotten.push({i,j});
                }  
            }
        }
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        
        while(!rotten.empty()){
            int k = rotten.size();
            cnt+=k;
            
            while(k--){
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();
                
                for(int i=0; i<4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if(nx<0 or ny<0 or nx>=m or ny>=n or grid[nx][ny]!=1){
                        continue;
                    }
                    
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            
                if(!rotten.empty()){
                        days++;
                    }  
            }
        if(cnt == total){
            return days;
        }
        else{
            return -1;
        }
            
    }
};