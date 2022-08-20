class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int  n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>visi(n, vector<int>(m,0));
        vector<vector<int>>ans(n, vector<int>(m,0));
        queue<pair<pair<int,int>, int>>q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    visi[i][j]=1;
                    q.push({{i, j}, 0});
                }
            }
        }
        
        vector<int>dx={0,1,0,-1};
        vector<int>dy={1,0,-1,0};
        
        while(!q.empty()){
            
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dist=q.front().second;
            ans[row][col]=dist;
            q.pop();
            
            for(int i=0; i<4; i++){
                
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visi[nrow][ncol]==0){
                    visi[nrow][ncol]=1;
                    q.push({{nrow, ncol}, dist+1});
                }
            }   
        }
        
        
        
        
        return ans;
        
    }
};