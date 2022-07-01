class Solution {
public:
    
    bool solve(vector<vector<char>>& board, string word, int i,int j, int n){
        
        if(n==word.length()) return 1;
        
        if(i<0 or i>=board.size() or j<0 or j>=board[0].size() or board[i][j]!=word[n]){
            return false;
        }
        
        //mark as visited 
        board[i][j]='0';
        
        bool temp = ( solve(board, word, i-1, j, n+1) or 
                     solve(board, word, i+1, j, n+1) or 
                     solve(board, word, i, j-1, n+1) or 
                     solve(board, word, i, j+1, n+1) );
        
        //Backtrack
        board[i][j]=word[n];
        
        return temp; 
    }
    
    
    
    

    
    bool exist(vector<vector<char>>& board, string word) {
     
        int n = board.size();
        int m = board[0].size();
        
        
        for(int i=0;i<n; i++){
            for(int j=0; j<m;j++){
                
                if(board[i][j]==word[0]){
                    if(solve(board, word,i,j,0)){
                        return true;
                    }
                }   
            }    
        }
       return false;    
    }
};