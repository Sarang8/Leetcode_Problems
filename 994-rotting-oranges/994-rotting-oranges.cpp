class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>>q;
        int fresh=0;
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        
        if(fresh==0){
            return 0;
        }
        
        vector<int>dx = {0, 0, 1, -1};
        vector<int>dy = {1, -1, 0, 0};
        
        int time=-1;
        
        while(!q.empty()){
            
            int size=q.size();
            time++;
            
            for(int i=0;i<size;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();

                for(int i=0;i<4;i++){

                    int nx = x + dx[i];
                    int ny = y+dy[i];

                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){
                        q.push({nx, ny});
                        grid[nx][ny]=2;
                        fresh--;     
                    }
                }   
            }
        }
        //cout<<fresh;
        
        if(fresh>0) return -1;
        if(time==-1) return 0;
        return time;
        
        
    }
};