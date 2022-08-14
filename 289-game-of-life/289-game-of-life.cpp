class Solution {
public:
    int find(int i, int j, vector<vector<int>>board, int &liveNum){
        
        if(i+1<board.size() && board[i+1][j]==1) liveNum++;
        if(i-1>=0 && board[i-1][j]==1) liveNum++;
        if(j+1<board[0].size() && board[i][j+1]==1) liveNum++;
        if(j-1>=0 && board[i][j-1]==1) liveNum++;
        if(i+1<board.size() && j+1<board[0].size() && board[i+1][j+1]==1) liveNum++;
        if(i+1<board.size() && j-1>=0 && board[i+1][j-1]==1) liveNum++;
        if(i-1>=0 && j+1<board[0].size() && board[i-1][j+1]==1) liveNum++;
        if(i-1>=0 && j-1>=0 && board[i-1][j-1]==1) liveNum++;
        return liveNum;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<int>>ans(n ,vector<int>(m,0));
        
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                int liveNum=0;
                liveNum = find(i, j, board, liveNum);
                // cout<<liveNum<<"  ";
                
                if(board[i][j]==1 && liveNum<2){
                    ans[i][j]=0;
                }
                
                else if(board[i][j]==1 && (liveNum==2 or liveNum==3)){
                    ans[i][j]=1;
                }
                
                else if(board[i][j]==1 && liveNum>3){
                    ans[i][j]=0;
                }
                
                else if(board[i][j]==0 && liveNum==3){
                    ans[i][j]=1;
                }
            }
            //cout<<endl;
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                board[i][j]=ans[i][j];
            }
        }
        
        
        
    }
};