class Solution {
public:
//     int find(int i, int j, vector<vector<int>>board, int &liveNum){
        
//         if(i+1<board.size() && board[i+1][j]==1) liveNum++;
//         if(i-1>=0 && board[i-1][j]==1) liveNum++;
//         if(j+1<board[0].size() && board[i][j+1]==1) liveNum++;
//         if(j-1>=0 && board[i][j-1]==1) liveNum++;
//         if(i+1<board.size() && j+1<board[0].size() && board[i+1][j+1]==1) liveNum++;
//         if(i+1<board.size() && j-1>=0 && board[i+1][j-1]==1) liveNum++;
//         if(i-1>=0 && j+1<board[0].size() && board[i-1][j+1]==1) liveNum++;
//         if(i-1>=0 && j-1>=0 && board[i-1][j-1]==1) liveNum++;
//         return liveNum;
//     }
    
//     void gameOfLife(vector<vector<int>>& board) {
        
//         int n=board.size();
//         int m=board[0].size();
        
//         vector<vector<int>>ans(n ,vector<int>(m,0));
        
        
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
                
//                 int liveNum=0;
//                 liveNum = find(i, j, board, liveNum);
//                 // cout<<liveNum<<"  ";
                
//                 if(board[i][j]==1 && liveNum<2){
//                     ans[i][j]=0;
//                 }
                
//                 else if(board[i][j]==1 && (liveNum==2 or liveNum==3)){
//                     ans[i][j]=1;
//                 }
                
//                 else if(board[i][j]==1 && liveNum>3){
//                     ans[i][j]=0;
//                 }
                
//                 else if(board[i][j]==0 && liveNum==3){
//                     ans[i][j]=1;
//                 }
//             }
//             //cout<<endl;
//         }
        
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 board[i][j]=ans[i][j];
//             }
//         }
        
    
    
    void gameOfLife(vector<vector<int>>& board) 
    {
        int n = board.size(), m = board[0].size();
        
        // 0 -> prev dead, now dead
        // 1 -> prev alive, now alive
        // 2 -> prev alive, now dead
        // 3 -> prev dead, now alive
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                int neigh = get_live_neighbors(board, i, j);
                
                if(!board[i][j])
                {
                    if(neigh == 3)
                        board[i][j] = 3;
                }
                else
                {
                    if(neigh < 2 or neigh > 3)
                        board[i][j] = 2;
                }
            }
        }
        
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                board[i][j] %= 2;
        
    }
private:
    int mx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int my[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    
    int get_live_neighbors(vector<vector<int>> &board, int a, int b)
    {
        int n = 0;
        
        for(int i = 0 ; i < 8 ; i++)
        {
            int x = mx[i] + a, y = my[i] + b;
            
            if(0 <= x and x < board.size() and 0 <= y and y < board[0].size())
                if(board[x][y] == 1 or board[x][y] == 2)
                    n++;
        }
        
        return n;
    
    
        
        
    }
};