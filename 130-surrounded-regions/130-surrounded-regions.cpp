class Solution {
public:
    //Easy only Sarang(just do adjustment thats all)
    
    void dfs(vector<vector<char>>& board, int i, int j){
        
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]!='O'){
            return;
        }
        
        board[i][j] = 'T';
        
        dfs(board, i-1, j);
        dfs(board, i+1, j);
        dfs(board, i, j-1);
        dfs(board, i, j+1);   
    }
    
    
    void solve(vector<vector<char>>& board) {
        
        int row=board.size();
        int col=board[0].size();
        
        
  //1....->First find 'o' on borders and then convert them to 'x' becaise the borders 'o' cant be surrounded regions
        
        //For last and first row
        for(int p=0; p<col; p++){
            if(board[0][p]=='O'){
                dfs(board, 0, p);
            }
             if(board[row-1][p]=='O'){
                dfs(board, row-1, p);
            }
        }
        
        //For fisrt and last col
        for(int p=0; p<row; p++){
            if(board[p][0]=='O'){
                dfs(board, p, 0);
            }
            if(board[p][col-1]=='O'){
                dfs(board, p, col-1);
            }
        }
        
        
 //2.->...Now traverse throght bpard and convert O to X
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        
    //3->.. Now again traverse and this time convert remaining T to back O
        //simple
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j]=='T'){
                    board[i][j]='O';
                }
            }
        }
        
          
    }
};