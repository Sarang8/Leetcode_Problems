class Solution {
public:
    
    bool isSafe(int row,int col,vector<vector<char>>& board,char k){
        
        for(int i=0; i<9; i++){
            
            //ROW CHECK
            if(board[row][i]==k) return false;
            
            //COL chech
            if(board[i][col]==k) return false;
            
            //3X3 SMALL MATRIX CHECK
            //VVVVVVVIMP FORMULA
            if( board[3*(row/3) + i/3][3*(col/3) + i%3] == k)  return false;   
        }
        
        return true;
    }
    
    
    
    
    bool solve(vector<vector<char>>& board){
        
        int row = board.size();
        int col = board[0].size();
        int n = board.size();   
        
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                
                if(board[row][col]=='.'){
                    for(char k='1'; k<='9'; k++){
                        if(isSafe(row, col,board,k)){
                            board[row][col]=k;
                            
                            if(solve(board)){
                                return true;
                            }
                            else{
                                board[row][col] = '.';  //BACKTRACK
                            } 
                        }
                    }
                    return false;
                }
            }
        }
        return true;        
    }
    
    
    

    
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);       
        
    }
};