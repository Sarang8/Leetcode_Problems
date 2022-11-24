class Solution {
public:
    bool solve(int i, int j, int ind, string &word, vector<vector<char>>& board){
        
        if(ind==word.size()){
            return true;
        }
        
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]!=word[ind]){
            return false;
        }
        
        
        board[i][j]='0';
        
        bool t1=0,t2=0,t3=0,t4=0;
        t1=solve(i+1, j, ind+1, word, board);
        t2=solve(i-1, j, ind+1, word, board);
        t3=solve(i, j+1, ind+1, word, board);
        t4=solve(i, j-1, ind+1, word, board);
        
        board[i][j] = word[ind];
        
        
        return t1 or t2 or t3 or t4;
        
    }
    
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(board[i][j]==word[0]){
                    if(solve(i, j, 0, word, board)){
                        return true;
                    }
                }
                
            }
        }
        
        return false;
    }
};